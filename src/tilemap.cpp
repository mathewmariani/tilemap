#include "tilemap.hpp"
#include "libs/pugixml.hpp"

// C/C++
#include <sstream>

namespace Tilemap {

void _parseMap(const pugi::xml_node& node, Map* out);
void _parseLayer(const pugi::xml_node& node, Layer* out);
void _parseLayerData(const pugi::xml_node& node, std::vector<unsigned int>* out);

void parseFromFile(const char* fileName, Map* out) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(fileName);

	if (!result) {
		printf("XML [%s] parsed with errors.\n", fileName);
		printf("Error description: %s.\n", result.description());
		return;
	}

	_parseMap(doc.child("map"), out);
}

void _parseMap(const pugi::xml_node& node, Map* out) {
	out->width = node.attribute("width").as_int();
	out->height = node.attribute("height").as_int();
	out->tileWidth = node.attribute("tilewidth").as_int();
	out->tileHeight = node.attribute("tileheight").as_int();

	// parse layers
	for (auto layer = node.child("layer"); layer; layer = layer.next_sibling("layer")) {
		Layer ref;
		_parseLayer(layer, &ref);

		out->layers.push_back(ref);
	}
}

void _parseLayer(const pugi::xml_node& node, Layer* out) {
	out->name = node.attribute("name").as_string();
	out->width = node.attribute("width").as_int();
	out->height = node.attribute("height").as_int();

	_parseLayerData(node.child("data"), &(out->data));
}

void _parseLayerData(const pugi::xml_node& node, std::vector<unsigned int>* out) {
	std::stringstream iss(node.text().as_string());

	unsigned int gid = 0;
	while (iss >> gid) {
		if (iss.peek() == ',' || iss.peek() == '\n') {
			iss.ignore();
		}

		out->push_back(gid);
	}
}

}	// tilemap

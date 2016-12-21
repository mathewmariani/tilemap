#pragma once

// C/C++
#include <string>
#include <vector>

namespace Tilemap {

typedef struct {
	std::string name;
	int width;
	int height;
	std::vector<unsigned int> data;
} Layer;

typedef struct {
	int width;
	int height;
	int tileWidth;
	int tileHeight;
	std::vector<Layer> layers;
} Map;

extern void parseFromFile(const char* fileName, Map* out);

}	// tilemap

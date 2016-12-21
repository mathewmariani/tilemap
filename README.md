# tilemap

A basic utility for reading [Tiled](http://www.mapeditor.org/) map files.

## Usage
```
Tilemap::Map map;
Tilemap::parseFromFile("data.xml", &map);

printf("%d\n", map.width);
printf("%d\n", map.height);
printf("%d\n", map.tileWidth);
printf("%d\n", map.tileHeight);
printf("%d\n", map.layers.size);

printf("%s\n", map.layers[0].name);
printf("%d\n", map.layers[0].width);
printf("%d\n", map.layers[0].height);
printf("%d\n", map.layers[0].data.size);
```

## Change Log

**v0.0.0**

- Only csv encoding is supported.

## License

This project is licensed under the terms of the MIT [License](LICENSE)

The project uses the [pugixml](http://pugixml.org/) library which are under the MIT License.

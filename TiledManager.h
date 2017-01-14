/*
 * TiledManager.h
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#ifndef TILEDMANAGER_H_
#define TILEDMANAGER_H_

#include "File.h"
#include "Tile.h"
#include "Map.h"

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class TiledManager {
	const std::string *tilePath;
	std::vector<Tile*> tiles;
	std::vector<sf::Texture*> textureTiles;
	int margin;
	unsigned int width;
	unsigned int height;
	bool errorLoadFile;

	void LoadPreferences( const std::string tilePath );
public:
	TiledManager( const std::string tilePath, const unsigned int width, const unsigned int height );
	~TiledManager();
	bool CreateTiled( sf::Vector2i pos, const unsigned int numberTiled );
	bool DelateTiled( sf::Vector2i pos );
	std::vector<sf::RectangleShape> GetTiles();
	int GetMargin();
	bool ErrorLoadPreferences();
	void LoadNewTiles(Map* map, unsigned int menuHwight);
};

#endif /* TILEDMANAGER_H_ */

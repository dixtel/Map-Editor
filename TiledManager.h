/*
 * TiledManager.h
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#ifndef TILEDMANAGER_H_
#define TILEDMANAGER_H_

#include "File.h"

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class TiledManager {
	int margin;
	bool errorLoadfile;

	const std::string *pathToTiledPreferences;

	std::vector<sf::RectangleShape*> tiles;
	std::vector<sf::Texture*> textureTiles;

	void LoadPreferences( const std::string pathToTiledPreferences );
public:
	TiledManager( const std::string pathToTiledPreferences );
	~TiledManager();
	void CreateTiled( sf::Vector2i pos, const unsigned int numberTiled );
	void Delatetiled( sf::Vector2i pos );
	std::vector<sf::RectangleShape*> GetTiles();
};

#endif /* TILEDMANAGER_H_ */

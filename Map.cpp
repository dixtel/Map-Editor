/*
 * Map.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: marcin
 */

#include "Map.h"

Map::Map( const int width, const int height, const std::string pathToTiledPreferences ) {
	this -> width = width;
	this -> height = height;

	map = new int *[height];

	for (int i = 0; i < height; ++i) {
		map[i] = new int [width];
	}
}

Map::~Map() {
	for (int i = 0; i < height; ++i) {
		delete[] map[i];
	}
	delete map;
	map = NULL;
}


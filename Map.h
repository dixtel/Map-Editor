/*
 * Map.h
 *
 *  Created on: Nov 19, 2016
 *      Author: marcin
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include "TiledManager.h"

class Map {
	int width;
	int height;
	int **map;

public:
	Map( const int width, const int height, const std::string pathToTiledPreferences );
	~Map();
};

#endif /* MAP_H_ */

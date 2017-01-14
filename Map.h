/*
 * Map.h
 *
 *  Created on: Nov 19, 2016
 *      Author: marcin
 */

#ifndef MAP_H_
#define MAP_H_

#include <iostream>

#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "File.h"


class Map {
	friend class TiledManager;
	unsigned int width;
	unsigned int height;
	int **board;

public:
	Map( const unsigned int width, const unsigned int height );
	~Map();
	void SetTile( const unsigned int x, const unsigned int y, const unsigned int numberTile );
	void DeleteTile( const unsigned int x, const unsigned int y );
	bool SaveMap( std::string pathToSaveMap, std::string fileName );
	bool LoadMap( std::string pathToMap);
	int **Get();
};

#endif /* MAP_H_ */

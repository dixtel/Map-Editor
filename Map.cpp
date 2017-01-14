/*
 * Map.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: marcin
 */

#include "Map.h"

Map::Map( const unsigned int width, const unsigned int height ) {
	this -> width = width;
	this -> height = height;

	board = new int*[height];

	for (unsigned int i = 0; i < height; ++i) {
		board[i] = new int[width];
	}

	for(unsigned int y = 0; y < height; ++y) {
		for(unsigned int x = 0; x < width; ++x) {
			board[y][x] = 0;
		}
	}
}

Map::~Map() {
	for (unsigned int i = 0; i < height; ++i) {
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
}

void Map::SetTile( const unsigned int x, const unsigned int y, const unsigned int numberTile ) {
	if(x < width && y < height) {
		board[y][x] = numberTile;
	}
}

void Map::DeleteTile( const unsigned int x, const unsigned int y ) {
	if(x < width && y < height) {
		board[y][x] = 0;
	}
}

bool Map::SaveMap( std::string pathToSaveMap, std::string fileName ) {
	std::vector <std::string> stringMap;
	for(unsigned int y = 0; y < height; ++y) {
		std::string line;
		for(unsigned int x = 0; x < width; ++x) {
			std::ostringstream convert;
			convert << board[y][x];
			line += convert.str();
		}
		stringMap.push_back( line );
	}

	std::string pathFile = pathToSaveMap + fileName;
	File file;
	return file.SaveFileToTextFile( stringMap, pathFile );
}

bool Map::LoadMap( std::string pathToMap) {
	File file;
	std::vector <std::string> mapFromFile = file.GetFile(pathToMap);

	if(mapFromFile.empty()) {
		return false;
	}

	for(unsigned int y = 0; y < mapFromFile.size(); ++y) {
		for(unsigned int x = 0; x < mapFromFile[0].size(); ++x) {
			std::string oneElement;
			oneElement.push_back(mapFromFile[y][x]);
			this -> board[y][x] = atoi( oneElement.c_str() );
		}
	}

	return true;
}

int **Map::Get() {
	return board;
}


/*
 * App.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#include "App.h"

App::App( const int widthMap, const int heightMap, const std::string pathToTiledPreferences ) {
	this -> widthMap = widthMap;
	this -> heightMap = heightMap;
	this ->selectedTiledNumber = 1;

	tiledManager = new TiledManager(pathToTiledPreferences );
	//window = new Window( widthMap, heightMap + 25, "Map Editor" );

}

App::~App() {

}


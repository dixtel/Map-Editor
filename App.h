/*
 * App.h
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#ifndef APP_H_
#define APP_H_

#include "TiledManager.h"
#include <string>
#include <SFML/Window.hpp>

class App {
	int widthMap;
	int heightMap;
	int selectedTiledNumber;

	TiledManager *tiledManager;

public:
	App( const int widthMap, const int heightMap, const std::string pathToTiledPreferences  );
	~App();
	void Start();
};

#endif /* APP_H_ */

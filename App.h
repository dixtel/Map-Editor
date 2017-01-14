/*
 * App.h
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#ifndef APP_H_
#define APP_H_

#include <string>
#include <iostream>
#include <sstream>
#include <SFML/Window.hpp>

#include "TiledManager.h"
#include "GUI.h"
#include "Render.h"
#include "Map.h"

class App {
	unsigned int editorWidth;
	unsigned int editorHeight;
	unsigned int menuHeight;
	int selectedTiledNumber;
	std::string pathToMap;

	TiledManager *tiledManager;
	GUI *gui;
	Render *render;
	Map *map;

	std::string ToString(unsigned int num);
	std::string GetTime( std::string type );
public:
	App( const int editorWidth, const int editorHeight, const int menuHeight );
	~App();
	void Start();
};

#endif /* APP_H_ */

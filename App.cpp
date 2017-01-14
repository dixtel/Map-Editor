/*
 * App.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#include "App.h"

App::App( const int editorWidth, const int editorHeight, const int menuHeight ) {
	this -> editorWidth = editorWidth;
	this -> editorHeight = editorHeight;
	this -> menuHeight = menuHeight;
	this -> selectedTiledNumber = 0;
	pathToMap = "Maps/";

	sf::Font font;
	font.loadFromFile("font/RobotoMono-Bold.ttf");

	tiledManager = new TiledManager("tiledpreferences.txt", editorWidth, editorHeight);
	gui = new GUI;
	render = new Render(editorWidth, editorHeight + menuHeight, "Map Editor", font);

	int widthMap = editorWidth / tiledManager -> GetMargin();
	int heightMap = editorHeight / tiledManager -> GetMargin();

	map = new Map(widthMap, heightMap);
}

App::~App() {
	delete tiledManager;
	delete gui;
	delete render;
	delete map;

	tiledManager = NULL;
	gui = NULL;
	render = NULL;
	map = NULL;
}

void App::Start() {
	gui -> CreateButton(sf::Vector2f(0, 5), sf::Vector2f(200, 50), "Ground", 1);
	gui -> CreateButton(sf::Vector2f(200, 5), sf::Vector2f(200, 50), "Player Spawn", 2);
	gui -> CreateButton(sf::Vector2f(400, 5), sf::Vector2f(200, 50), "End Map", 3);
	gui -> CreateButton(sf::Vector2f(600, 5), sf::Vector2f(200, 50), "Block Enemy", 4);
	gui -> CreateButton(sf::Vector2f(800, 5), sf::Vector2f(200, 50), "Spawn Enemy 1", 5);
	gui -> CreateButton(sf::Vector2f(0, 50), sf::Vector2f(200, 50), "Star" , 6);
	gui -> CreateButton(sf::Vector2f(200, 50), sf::Vector2f(200, 50), "Delete", 999);
	gui -> CreateButton(sf::Vector2f(400, 50), sf::Vector2f(200, 50), "Save Map", 998);
	gui -> CreateButton(sf::Vector2f(600, 50), sf::Vector2f(200, 50), "Load Map", 997);


	while(render -> GetWindow() -> isOpen()) {

		sf::Event event;
		while(render -> GetWindow() -> pollEvent(event)) {
			sf::Vector2i posMouse = sf::Mouse::getPosition(*render -> GetWindow());

			if(event.type == sf::Event::Closed) {
				render -> GetWindow() -> close();
			}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if(selectedTiledNumber >= 1 && selectedTiledNumber <= 6) {
					if(posMouse.y > menuHeight && posMouse.y < (editorHeight + menuHeight) &&
							posMouse.x > 0 && posMouse.x < editorWidth ) {
						if( tiledManager -> CreateTiled( posMouse , selectedTiledNumber )) {
							unsigned int x = posMouse.x / tiledManager -> GetMargin();
							unsigned int y = (posMouse.y - menuHeight) / tiledManager -> GetMargin();
							map -> SetTile(x, y, selectedTiledNumber);
						}
					}
				}
				if(selectedTiledNumber == 999) {
					if( posMouse.y > menuHeight && posMouse.y < (editorHeight + menuHeight) &&
							posMouse.x > 0 && posMouse.x < editorWidth ) {
						if( tiledManager -> DelateTiled( posMouse ) ) {
							unsigned int x = posMouse.x / tiledManager -> GetMargin();
							unsigned int y = (posMouse.y - menuHeight) / tiledManager -> GetMargin();
							map -> DeleteTile(x, y);
						}
					}
				}
			}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if( posMouse.y > menuHeight && posMouse.y < (editorHeight + menuHeight) &&
						posMouse.x > 0 && posMouse.x < editorWidth ) {
					if( tiledManager -> DelateTiled( posMouse ) ) {
						unsigned int x = posMouse.x / tiledManager -> GetMargin();
						unsigned int y = (posMouse.y - menuHeight) / tiledManager -> GetMargin();
						map -> DeleteTile(x, y);
					}
				}
			}

			gui -> SetEventButton(event, sf::Mouse::getPosition(*render -> GetWindow()));
		}

		if(gui -> GetValueButtonClicked() != 0) selectedTiledNumber = gui -> GetValueButtonClicked();

		if(selectedTiledNumber == 998) {
			if(map -> SaveMap( pathToMap, "map-Data:" + GetTime("fulltime") + ".txt" )) {
				selectedTiledNumber = 0;
			}
			else {
				std::cout << "Error save map\n";
				selectedTiledNumber = 0;
			}
		}
		else if(selectedTiledNumber == 997) {
			if( map -> LoadMap( pathToMap + "level1.txt") ) {
				tiledManager -> LoadNewTiles(map, menuHeight);
				selectedTiledNumber = 0;
			}
			else {
				std::cout << "Error load map\n";
				selectedTiledNumber = 0;
			}
		}

//		int **test = map -> Get();
//		for(unsigned int y = 0; y < int(editorHeight / 25); ++y) {
//			for(unsigned int x = 0; x < int(editorWidth / 25); ++x) {
//				std::cout << test[y][x] << " ";
//			}
//			std::cout<<std::endl;
//		}
//		std::cout<<std::endl<<std::endl

		render -> Clear();
		render -> Draw(*gui);
		render -> Draw(tiledManager -> GetTiles());
		render -> DrawText("Button selected value = " + ToString(selectedTiledNumber), sf::Vector2f(10, 110));
		render -> DrawText("Tiles size = " + ToString(tiledManager -> GetTiles().size()), sf::Vector2f(600, 110));
		render -> Display();

	}
}

std::string App::ToString(unsigned int num) {
	std::stringstream convert;
	convert << num;
	return convert.str();
}

std::string App::GetTime( std::string type ) {
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);

	std::ostringstream convert;

	if(type == "fulltime") {
		std::string time;

		convert << ltm -> tm_hour;
		time += convert.str() + "-";

		convert.str("");
		convert.clear();

		convert << 1 + ltm -> tm_min ;
		time += convert.str() + "-";

		convert.str("");
		convert.clear();

		convert << 1 + ltm -> tm_sec;
		time += convert.str();

		return time;
	}
	else if(type == "second") {
		std::string time;
		convert << ltm -> tm_sec + 1;
		time += convert.str();

		return time;
	}
	else if( type == "minute" ) {
		std::string time;
		convert << ltm -> tm_min + 1;
		time += convert.str();

		return time;
	}
	else if( type == "hour" ) {
		std::string time;
		convert << ltm -> tm_hour;
		time += convert.str();

		return time;
	}

	return "Error get time";
}




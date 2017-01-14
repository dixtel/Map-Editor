/*
 * TiledManager.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#include "TiledManager.h"

TiledManager::TiledManager( const std::string tilePath, const unsigned int width, const unsigned int height ) {
	this -> tilePath = &tilePath;
	this -> errorLoadFile = false;
	this -> margin = 0;

	LoadPreferences( tilePath );
}

TiledManager::~TiledManager() {

}

void TiledManager::LoadPreferences( const std::string tilePath ) {
	File file;
	std::vector <std::string> allPreferences = file.GetFile( tilePath );

	if( allPreferences.empty() ) {
		errorLoadFile = true;
	}

	std::string margin = allPreferences[0].substr( allPreferences[0].find(':') + 1 );
	int tmpMargin = std::atoi( margin.c_str() );

	if(tmpMargin <= 0 || tmpMargin > 999) {
		this -> margin = 10;
	}
	else {
		this -> margin = tmpMargin;
	}


	for(unsigned int i = 1; i < allPreferences.size(); ++i) {
		std::string tiledImage = allPreferences[i].substr( allPreferences[i].find(':') + 1 );
		textureTiles.push_back( new sf::Texture );
		textureTiles[textureTiles.size() - 1] -> loadFromFile(tiledImage);
	}
}

bool TiledManager::CreateTiled( sf::Vector2i pos, const unsigned int numberTiled ) {
	if( !(numberTiled > 0 && numberTiled <= textureTiles.size()) ) return false;

	int x = int(pos.x / margin) * margin;
	int y = int(pos.y / margin) * margin;

	for(unsigned int i = 0; i < tiles.size(); ++i ) {
		sf::Vector2f posTile = tiles[i] -> Get().getPosition();
		if( posTile.x == x && posTile.y == y) {
			if(tiles[i] -> GetValue() == numberTiled) {
				return false;
			}
			else {
				DelateTiled(pos);
			}
		}
	}

	tiles.push_back( new Tile(sf::Vector2f(x, y), sf::Vector2f(margin, margin), numberTiled, textureTiles[numberTiled - 1]) );

	return true;
}

bool TiledManager::DelateTiled( sf::Vector2i pos ) {
	for(unsigned int i = 0; i < tiles.size(); ++i) {
		sf::Vector2f positionTile = tiles[i] -> Get().getPosition();
		if(pos.x >= positionTile.x && pos.x < (positionTile.x + margin) &&
				pos.y >= positionTile.y && pos.y < (positionTile.y + margin)) {
			tiles.erase( tiles.begin() + i );
			return true;
		}
	}
	return false;
}

std::vector<sf::RectangleShape> TiledManager::GetTiles() {
	std::vector<sf::RectangleShape> tiles;
	for (unsigned int i = 0; i < this -> tiles.size(); ++i) {
		tiles.push_back( this -> tiles[i] -> Get() );
	}
	return tiles;
}

int TiledManager::GetMargin() {
	return margin;
}

bool TiledManager::ErrorLoadPreferences() {
	return errorLoadFile;
}

void TiledManager::LoadNewTiles(Map* map, unsigned int menuHwight) {
	tiles.clear();

	for(unsigned int y = 0; y < map -> height; ++y) {
		for(unsigned int x = 0; x < map -> width; ++x) {
			if(map -> board[y][x] > 0 && map -> board[y][x] <= textureTiles.size() ) {
				CreateTiled( sf::Vector2i( int(x * margin), int(y * margin) + menuHwight ), map -> board[y][x] );
			}
		}
	}
}




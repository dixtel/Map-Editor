/*
 * TiledManager.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#include "TiledManager.h"

TiledManager::TiledManager( const std::string pathToTiledPreferences ) {
	this -> pathToTiledPreferences = &pathToTiledPreferences;
	this -> errorLoadfile = false;
	this -> margin = 0;

	LoadPreferences( pathToTiledPreferences );
}

TiledManager::~TiledManager() {

}

void TiledManager::LoadPreferences( const std::string pathToTiledPreferences ) {
	File file;
	std::vector <std::string> allPreferences = file.GetFile( pathToTiledPreferences );

	if( allPreferences.empty() ) {
		errorLoadfile = true;
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

void TiledManager::CreateTiled( sf::Vector2i pos, const unsigned int numberTiled ) {
	if( !(numberTiled >= 0 && numberTiled <= textureTiles.size()) ) return;

	int x = int(pos.x / margin) * margin;
	int y = int(pos.y / margin) * margin;

	for(unsigned int i = 0; i < tiles.size(); ++i ) {
		sf::Vector2f posTile = tiles[i] -> getPosition();
		if( posTile.x == x && posTile.y  == y) return;
	}

	tiles.push_back( new sf::RectangleShape );
	tiles[ (tiles.size() - 1 ) ] -> setSize( sf::Vector2f(margin + 50, margin));
	tiles[ (tiles.size() - 1 ) ] -> setPosition( sf::Vector2f(x, y));
	tiles[ (tiles.size() - 1 ) ] -> setTexture(textureTiles[numberTiled]);
}

void TiledManager::Delatetiled( sf::Vector2i pos ) {
	for(unsigned int i = 0; i < tiles.size(); ++i) {
		sf::Vector2f positionTile = tiles[i] -> getPosition();
		if(pos.x >= positionTile.x && pos.x <= (positionTile.x + margin) && pos.y >= positionTile.y && pos.y <= (positionTile.y + margin)) {
			tiles.erase( tiles.begin() + i );
			return;
		}
	}
}

std::vector<sf::RectangleShape*> TiledManager::GetTiles() {
	return tiles;
}


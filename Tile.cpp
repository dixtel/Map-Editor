/*
 * Tile.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: marcin
 */

#include "Tile.h"

Tile::Tile( sf::Vector2f pos, const sf::Vector2f size, const unsigned int value, sf::Texture *texture ) {
	this -> texture = *texture;
	tile.setPosition(pos);
	tile.setSize(size);
	tile.setTexture(texture);

	this -> value = value;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

sf::RectangleShape Tile::Get() {
	return tile;
}

int Tile::GetValue() {
	return value;
}



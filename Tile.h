/*
 * Tile.h
 *
 *  Created on: Nov 28, 2016
 *      Author: marcin
 */

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>

class Tile {
	sf::Texture texture;
	sf::RectangleShape tile;
	unsigned int value;
public:
	Tile( sf::Vector2f pos, const sf::Vector2f size, const unsigned int value, sf::Texture *texture );
	~Tile();
	sf::RectangleShape Get();
	int GetValue();

};

#endif /* TILE_H_ */

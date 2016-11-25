/*
 * Button.h
 *
 *  Created on: Nov 20, 2016
 *      Author: marcin
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
	sf::Texture normalTexture;
	sf::Texture clickedTexture;
	sf::RectangleShape normal;
	sf::RectangleShape clicked;
	sf::Font font;
	sf::Text text;
	sf::Vector2f size;
	bool state; // false = disable, true = enable
	unsigned int value;
public:
	Button(sf::Vector2f position, sf::Vector2f size, std::string text, const unsigned int value);
	void CheckClick(sf::Vector2i mouseClick);
	void ChangeState(bool state);
	void SetText(sf::String text);
	bool IsClicked();
	sf::RectangleShape GetButton();
	sf::Text GetText();
	unsigned int GetValue();
	~Button();
};

#endif /* BUTTON_H_ */

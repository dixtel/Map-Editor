/*
 * Button.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: marcin
 */

#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, std::string text, const unsigned int value) {

	normalTexture.loadFromFile("image/buttonnormal.png");
	clickedTexture.loadFromFile("image/buttonclicked.png");

	font.loadFromFile("font/RobotoMono-Bold.ttf");

	this -> normal.setSize(size);
	this -> normal.setTexture(&normalTexture);
	this -> normal.setPosition(position);

	this -> clicked.setSize(size);
	this -> clicked.setTexture(&clickedTexture);
	this -> clicked.setPosition(position);

	int fontWidth = (text.size() * 8);
	int fontXPosition = position.x + (( size.x - fontWidth ) / 2);

	this -> text.setString(text);
	this -> text.setFont(font);
	this -> text.setScale(0.45, 0.5);
	this -> text.setPosition( fontXPosition , (position.y + (size.y / 2)) - 9 );

	this -> state = false;
	this -> size = size;

	this -> value = value;
}

Button::~Button() {

}

void Button::CheckClick(sf::Vector2i mouseClick) {
	if(mouseClick.x >= normal.getPosition().x && mouseClick.x <= (normal.getPosition().x + size.x) &&
	   mouseClick.y >= normal.getPosition().y && mouseClick.y <= (normal.getPosition().y + size.y) ) {
		ChangeState(true);
	}
	else {
		ChangeState(false);
	}
}

void Button::ChangeState(bool state) {
	this -> state = state;
}

void Button::SetText(sf::String text) {
	this -> text.setString( text );
}

bool Button::IsClicked() {
	return state;
}

sf::RectangleShape Button::GetButton() {
	if(state) {
		return clicked;
	}
	return normal;
}

sf::Text Button::GetText() {
	return text;
}

unsigned int Button:: GetValue() {
	return value;
}








/*
 * Render.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: marcin
 */

#include "Render.h"

Render::Render(const int width, const int height, const std::string title, sf::Font font) {
	this -> window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	this -> font = font;
}

Render::~Render() {

}

void Render::Clear() {
	window -> clear();
}

void Render::Draw(GUI gui) {
	for(unsigned int i = 0; i < gui.button.size(); ++i ) {
		window -> draw( gui.button[i] -> GetButton() );
		window -> draw( gui.button[i] -> GetText() );
	}
}

void Render::DrawText(const std::string text, sf::Vector2f position) {
	sf::Text textToDraw;
	textToDraw.setString(text);
	textToDraw.setPosition(position);
	textToDraw.setColor(sf::Color::White);
	textToDraw.setFont(font);
	window -> draw(textToDraw);
}

void Render::Draw(std::vector <sf::RectangleShape*> object) {
	for(unsigned int i = 0; i < object.size(); ++i ) {
		window -> draw( *object[i] );
	}
}

void Render::Display() {
	window -> display();
}

sf::RenderWindow *Render::GetWindow() {
	return window;
}





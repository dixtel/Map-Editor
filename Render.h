/*
 * Render.h
 *
 *  Created on: Nov 22, 2016
 *      Author: marcin
 */

#ifndef RENDER_H_
#define RENDER_H_

#include <SFML/Window.hpp>
#include <vector>

#include "GUI.h"

class Render {
	sf::RenderWindow *window;
	sf::Font font;
public:
	Render(const int width, const int height, const std::string title, sf::Font font);
	~Render();
	void Clear();
	void Draw(GUI gui);
	void DrawText(const std::string text, sf::Vector2f position);
	void Draw(std::vector <sf::RectangleShape> object);
	void Display();
	sf::RenderWindow *GetWindow();

};

#endif /* RENDER_H_ */

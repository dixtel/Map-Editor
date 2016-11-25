/*
 * GUI.h
 *
 *  Created on: Nov 20, 2016
 *      Author: marcin
 */

#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.h"

class GUI {
	friend class Render;
	std::vector <Button*> button;
public:
	GUI();
	~GUI();
	void CreateButton(sf::Vector2f position, sf::Vector2f size, std::string text, const unsigned int value);
	void SetEventButton(sf::Event event, sf::Vector2i mousePos);
	unsigned int GetValueButtonClicked();
};

#endif /* GUI_H_ */

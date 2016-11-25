#include <iostream>
#include <vector>
#include <sstream>
#include <SFML/Window.hpp>

#include "GUI.h"
#include "Render.h"
#include "TiledManager.h"

std::string toString(unsigned int num);

int main(int argc, char **argv) {
	sf::Font font;
	font.loadFromFile("Roboto-Light.ttf");

	const int WEIGHTMAP = 1000;
	const int HEIGHTMAP = 500;
	const int EDITORPANELHEIGHT = 200;

	TiledManager tiledManager("tiledpreferences.txt");
	Render render(WEIGHTMAP, HEIGHTMAP + EDITORPANELHEIGHT, "My first GUI v0.1", font);
	GUI gui;

	gui.CreateButton(sf::Vector2f(0, 5), sf::Vector2f(200, 50), "Ground", 1);
	gui.CreateButton(sf::Vector2f(200, 5), sf::Vector2f(200, 50), "Player Spawn", 2);
	gui.CreateButton(sf::Vector2f(400, 5), sf::Vector2f(200, 50), "End Map", 3);
	gui.CreateButton(sf::Vector2f(600, 5), sf::Vector2f(200, 50), "Block Enemy", 4);
	gui.CreateButton(sf::Vector2f(800, 5), sf::Vector2f(200, 50), "Spawn Enemy 1", 5);
	gui.CreateButton(sf::Vector2f(0, 50), sf::Vector2f(200, 50), "Star" , 6);
	gui.CreateButton(sf::Vector2f(200, 50), sf::Vector2f(200, 50), "Delete", 999);

	unsigned int selectButton = 0;

	while(render.GetWindow() -> isOpen()) {

		sf::Event event;
		while(render.GetWindow() -> pollEvent(event)) {

			if(event.type == sf::Event::Closed) {
				render.GetWindow() -> close();
			}

			gui.SetEventButton(event, sf::Mouse::getPosition(*render.GetWindow()));
		}

		if(gui.GetValueButtonClicked() != 0) selectButton = gui.GetValueButtonClicked();

		sf::Vector2i posMouse = sf::Mouse::getPosition(*render.GetWindow());
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if(posMouse.y > EDITORPANELHEIGHT && posMouse.y < HEIGHTMAP + EDITORPANELHEIGHT &&
				posMouse.x > 0 && posMouse.x < WEIGHTMAP) {
				tiledManager.CreateTiled(sf::Mouse::getPosition(*render.GetWindow()), selectButton );
			}
			if(selectButton == 999) {
				if(posMouse.y > EDITORPANELHEIGHT && posMouse.y < HEIGHTMAP + EDITORPANELHEIGHT &&
					posMouse.x > 0 && posMouse.x < WEIGHTMAP) {
					tiledManager.Delatetiled(sf::Mouse::getPosition(*render.GetWindow()));
				}
			}
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			if(posMouse.y >= EDITORPANELHEIGHT && posMouse.y <= HEIGHTMAP + EDITORPANELHEIGHT &&
				posMouse.x >= 0 && posMouse.x <= WEIGHTMAP) {
				tiledManager.Delatetiled(sf::Mouse::getPosition(*render.GetWindow()));
			}
		}


		render.Clear();
		render.Draw(gui);
		render.Draw(tiledManager.GetTiles());
		render.DrawText("Button selected value = " + toString(selectButton), sf::Vector2f(10, 110));
		render.DrawText("Tiles size = " + toString(tiledManager.GetTiles().size()), sf::Vector2f(370, 110));
		render.Display();

	}

	return 1;
}

std::string toString(unsigned int num) {
	std::stringstream convert;
	convert << num;
	return convert.str();
}



/*
 * GUI.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: marcin
 */

#include "GUI.h"

GUI::GUI() {

}

GUI::~GUI() {


}

void GUI::CreateButton(sf::Vector2f position, sf::Vector2f size, std::string text, const unsigned int value) {
	button.push_back( new Button(position, size, text, value) );
}

void GUI::SetEventButton(sf::Event event, sf::Vector2i mousePos) {
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for(unsigned int i = 0; i < button.size(); ++i) {
			button[i] -> CheckClick(mousePos);
		}
	}
	else {
		for(unsigned int i = 0; i < button.size(); ++i) {
			button[i] -> ChangeState(false);
		}
	}
}

unsigned int GUI::GetValueButtonClicked() {
	for(unsigned int i = 0; i < button.size(); ++i) {
		if(button[i] -> IsClicked()) {
			return button[i] -> GetValue();
		}
	}
	return 0;
}






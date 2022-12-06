//
// Created by meanx on 06/12/2022.
//

#include "EngineCore/IO/Keyboard.h"

bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

//Todo: Make Time delayed press
bool Keyboard::isKeyTapped(sf::Keyboard::Key key) {
    return false
}

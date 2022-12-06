//
// Created by meanx on 06/12/2022.
//

#ifndef SFML_PINGPONG_KEYBOARD_H
#define SFML_PINGPONG_KEYBOARD_H

#include <SFML/Graphics.hpp>

class Keyboard final {
private:
    std::map<sf::Keyboard::Key, double> m_tappedKeys;

public:
    Keyboard() = default;

    static bool isKeyPressed(sf::Keyboard::Key key);

    bool isKeyTapped(sf::Keyboard::Key key)
};


#endif //SFML_PINGPONG_KEYBOARD_H

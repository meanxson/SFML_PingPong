//
// Created by meanx on 06/12/2022.
//

#include <SFML/Graphics/Color.hpp>
#include <string>

#ifndef SFML_PINGPONG_CONSTANTS_H
#define SFML_PINGPONG_CONSTANTS_H

#endif //SFML_PINGPONG_CONSTANTS_H

namespace Constants {
    const int STANDARD_SCREEN_WIDTH = 1920;
    const int STANDARD_SCREEN_HEIGHT = 1080;
    const sf::Color BACKGROUND_COLOR = sf::Color(255, 255, 255);
    const std::string PROJECT_NAME = "PingPong";

    const std::string THIN_FONT = "engine/fonts/Roboto-Thin.ttf";
    const std::string MEDIUM_FONT = "engine/fonts/Roboto-Medium.ttf";


    const double Epsilon = 0.000001;
}
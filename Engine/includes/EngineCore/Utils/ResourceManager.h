//
// Created by meanx on 06/12/2022.
//

#ifndef SFML_PINGPONG_RESOURCEMANAGER_H
#define SFML_PINGPONG_RESOURCEMANAGER_H


#include <SFML/Graphics/Font.hpp>
#include <memory>

class ResourceManager {
private:
    std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;


    static std::shared_ptr<sf::Font> loadFont(const std::string &filename);
};


#endif //SFML_PINGPONG_RESOURCEMANAGER_H

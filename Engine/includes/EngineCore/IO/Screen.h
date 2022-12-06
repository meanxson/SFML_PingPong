//
// Created by meanx on 06/12/2022.
//

#ifndef SFML_PINGPONG_SCREEN_H
#define SFML_PINGPONG_SCREEN_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <EngineCore/Maths/Vector2.h>
#include "EngineCore/Utils/Constants.h"
#include "GL/gl.h"

class Screen final {
private:
    int m_scene = 0;
    bool m_renderVideo = false;
    std::vector<sf::Texture> m_renderSequence;

    std::string m_title;
    sf::Color m_backgroundColour;

    const std::shared_ptr<sf::RenderWindow> m_window = std::make_shared<sf::RenderWindow>();
public:
    void open(int screenWidth = Constants::STANDARD_SCREEN_WIDTH, int screenHeight = Constants::STANDARD_SCREEN_HEIGHT,
              const std::string &name = Constants::PROJECT_NAME, bool verticalSync = false,
              sf::Color backgroundColour = Constants::BACKGROUND_COLOR, sf::Uint32 style = sf::Style::Default);

    void display();

    void clear();

    [[nodiscard]] bool hasFocus() const { return m_window->hasFocus(); }

    void drawTetragon(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3, const Vector2 &p4, sf::Color color);

    void drawText(const std::string &string, const Vector2 &position, int size, sf::Color color);

    void drawText(const sf::Text &text);

    void drawSprite(const sf::Sprite &sprite);

    void setTitle(const std::string &title);

    [[nodiscard]] std::string title() const { return m_title; };

    bool isOpen();

    [[nodiscard]] int width() const { return m_window->getSize().x; }

    [[nodiscard]] int height() const { return m_window->getSize().y; }

    void close();

    void setMouseCursorVisible(bool visible);

    void prepareToGlDrawMesh();

    void glDrawMesh(GLfloat *geometry, GLfloat *view, GLfloat *model, size_t count);

    [[nodiscard]] std::shared_ptr<sf::RenderWindow> renderWindow() { return m_window; }

    void pushGLStates() { m_window->pushGLStates(); };

    void popGLStates() { m_window->popGLStates(); };

    void startRender();

    void stopRender();

};


#endif //SFML_PINGPONG_SCREEN_H

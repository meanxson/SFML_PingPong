//
// Created by meanx on 06/12/2022.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include "EngineCore/IO/Screen.h"

void
Screen::open(int screenWidth, int screenHeight, const std::string &name, bool verticalSync, sf::Color backgroundColour,
             sf::Uint32 style) {
    m_title = name;
    m_backgroundColour = backgroundColour;

    sf::ContextSettings settings;
    settings.depthBits = 12;
    settings.antialiasingLevel = 1;

    m_window->create(sf::VideoMode(screenWidth, screenHeight), name, style, settings);
    m_window->setVerticalSyncEnabled(verticalSync);

}

void Screen::display() {
    sf::Event event{};
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }

    std::string title = m_title;
    m_window->setTitle(title);

    if (m_renderVideo) {
        sf::Texture copyTexture;
        copyTexture.create(m_window->getSize().x, m_window->getSize().y);
        copyTexture.update(*m_window);
        m_renderSequence.push_back(copyTexture);
    }

    m_window->display();
}

void Screen::clear() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    m_window->clear(m_backgroundColour);
}

void Screen::startRender() {
    stopRender();
    //Log -> log
    m_renderVideo = true;
}

void Screen::stopRender() {
    if (m_renderVideo) {
        //Todo: Log

        std::string c = "rm film/png/*.png";
        popen(c.c_str(), "w");
        int i = 0;
        for (; i < m_renderSequence.size(); ++i) {
            m_renderSequence[i].copyToImage().saveToFile("film/png/" + std::to_string(i) + ".png");
            //Log::Log();
        }
        m_renderSequence.clear();

        //Log::Log();

        c = "ffmpeg -stats -r 60 -i film/png/%d.png -vcodec libx264 -crf 1 -pix_fmt yuv420p -frames " +
            std::to_string(i) + " film/mp4/" + std::to_string(m_scene) + "_" + m_title + "_" + std::to_string(rand()) +
            ".mp4";

        popen(c.c_str(), "w");
        m_scene++;
        m_renderVideo = false;
        //Log::();
    }
}

void Screen::drawTetragon(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3, const Vector2 &p4, sf::Color color) {

}

void Screen::drawText(const std::string &string, const Vector2 &position, int size, sf::Color color) {
    sf::Text text;

    // text.setFont(*ResourceManager::loadFont(Constants::MEDIUM_FONT));

    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Italic);
    text.setPosition(static_cast<float>(position.x()), static_cast<float>(position.y()));

    text.setString(string);

    m_window->draw(text);
}

void Screen::drawText(const sf::Text &text) {
    m_window->draw(text);
}

void Screen::drawSprite(const sf::Sprite &sprite) {
    m_window->draw(sprite);
}

void Screen::setTitle(const std::string &title) {
    m_title = title;
}

bool Screen::isOpen() {
    return m_window->isOpen();
}

void Screen::close() {
    m_window->close();
}

void Screen::setMouseCursorVisible(bool visible) {
    m_window->setMouseCursorVisible(visible);
}

void Screen::prepareToGlDrawMesh() {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);

    glDisable(GL_LIGHTING);

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_NOTEQUAL, 0.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, m_window->getSize().x, m_window->getSize().y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(m_window->getSize().x) / m_window->getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.0f, 100.f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glMatrixMode(GL_MODELVIEW);
}

void Screen::glDrawMesh(GLfloat *geometry, GLfloat *view, GLfloat *model, size_t count) {
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), geometry);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), geometry + 3);

    glLoadIdentity();

    glLoadMatrixf(view);
    glMultMatrixf(model);

    // Draw the mesh
    glDrawArrays(GL_TRIANGLES, 0, count);
}

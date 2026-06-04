#pragma once
#include "../logger.hpp"
#include <SFML/Graphics.hpp>

class Renderer {
private:
    Logger log;
    sf::RenderWindow window;
public:
    Renderer(int width = 800, int height = 600);
    void render();
};
#pragma once
#include "../logger.hpp"
#include <fstream>
#include <SFML/Graphics.hpp>
#include "../assets/logo.h"
#include "../assets/icon.h"
#include "../assets/Merriweather.h"
#include "../assets/FiraCode.h"

class Renderer {
private:
    Logger& log;
    sf::RenderWindow window;
    sf::Font titleFont;
    sf::Font defaultFont;
public:
    Renderer(Logger& log, int width = 800, int height = 600);
    void splash();
    void render();
};
#include <iostream>
#include "logger.cpp"
#include <SFML/Graphics.hpp>

int main() {
    Logger log;
    log.info("BarpVN v0.0.0 by DessieOwO"); //Version number will probably be a variable asp. 
    log.warn("This is a development build, expect crashes and bugs!");

    sf::RenderWindow window(sf::VideoMode(800, 600), "BarpVN");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}
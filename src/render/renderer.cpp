#include "renderer.hpp"

Renderer::Renderer(int width, int height) {
    log.debug("Creating window...");
    window.create(sf::VideoMode(width, height), "BarpVN");
    if (!window.isOpen()) {
        log.fatal("Failed to create window!");
        exit(EXIT_FAILURE);
    }
    log.debug("Window created successfully!");
}

void Renderer::render() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                log.info("Closed by window close event.");
            }
        }
        window.clear();
        window.display();
    }
}
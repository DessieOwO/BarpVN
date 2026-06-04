#include "renderer.hpp"

Renderer::Renderer(Logger& log,int width, int height) : log(log) {
    log.debug("Creating window...");
    window.create(sf::VideoMode(width, height), "BarpVN");
    
    if (!window.isOpen()) {
        log.fatal("Failed to create window!");
        exit(EXIT_FAILURE);
    }
    log.debug("Window created successfully!");

    log.debug("Loading window icon...");
    sf::Image icon;
    if (icon.loadFromMemory(src_assets_icon_png, src_assets_icon_png_len)) {
        log.debug("Window icon loaded successfully!");
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    } else {
        log.error("Icon image not found!");
    }
    log.debug("Loading fonts...");
    if (titleFont.loadFromMemory(src_assets_Merriweather_ttf, src_assets_Merriweather_ttf_len)) {
        log.debug("Title font loaded successfully!");
    } else {
        log.error("Title font not found!");
    }
    if (defaultFont.loadFromMemory(src_assets_FiraCode_ttf, src_assets_FiraCode_ttf_len)) {
        log.debug("Default font loaded successfully!");
    } else {
        log.error("Default font not found!");
    }
}

void Renderer::splash() {
    log.debug("Loading splash screen...");
    sf::Texture logo;
    if (!logo.loadFromMemory(src_assets_logo_png, src_assets_logo_png_len)) {
        log.error("Splash image not found!");
        return;
    }
    sf::Sprite sprite(logo);

    sf::Vector2 windowSize = window.getSize();
    sf::Vector2 logoSize = logo.getSize();
    sprite.setPosition((
        (windowSize.x - logoSize.x) / 2.0f),
        ((windowSize.y - logoSize.y) / 2.0f)
    );

    sf::Text appInfo;
    appInfo.setFont(titleFont);
    appInfo.setString("BarpVN v0.0.0");
    appInfo.setCharacterSize(24);
    appInfo.setFillColor(sf::Color::White);
    sf::Vector2f textSize = appInfo.getLocalBounds().getSize();
    float targetY = sprite.getPosition().y;
    sf::FloatRect appInfoBounds = appInfo.getLocalBounds();
    appInfo.setPosition(
        (window.getSize().x - appInfoBounds.width) / 2.f,
        targetY / 2.f
    );

    sf::Text noticeText;
    noticeText.setFont(defaultFont);
    noticeText.setString("This is a development build, expect crashes and bugs!");
    noticeText.setCharacterSize(18);
    noticeText.setFillColor(sf::Color::White);
    sf::FloatRect noticeTextBounds = noticeText.getLocalBounds();
    noticeText.setPosition(
        (window.getSize().x - noticeTextBounds.width) / 2.f,
        targetY + logoSize.y + 20.f //Idk what I'm doing anymore, just winging it and hoping the numbers look good
    );

    log.debug("Displaying splash screen...");

    sf::Clock clock;
    while (window.isOpen() && clock.getElapsedTime().asSeconds() < 3) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                log.info("Closed by window close event.");
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(appInfo);
        window.draw(noticeText);
        window.display();    
    }
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
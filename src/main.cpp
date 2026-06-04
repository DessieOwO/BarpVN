#include <iostream>
#include "logger.hpp"
#include "render/renderer.hpp"

int main() {
    Logger log;
    Renderer renderer;
    log.info("BarpVN v0.0.0 by DessieOwO"); //Version number will probably be a variable asp. 
    log.warn("This is a development build, expect crashes and bugs!");

    renderer.render();

    return 0;
}
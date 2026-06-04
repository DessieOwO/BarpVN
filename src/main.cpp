#include <iostream>
#include "logger.cpp"

int main() {
    Logger log;
    log.info("BarpVN v0.0.0 by DessieOwO"); //Version number will probably be a variable asp. 
    log.warn("This is a development build, expect crashes and bugs!");
    return 0;
}
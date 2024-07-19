#ifndef DESIGN_PATTERN_SCREEN_H
#define DESIGN_PATTERN_SCREEN_H

#include <iostream>

class Screen {
public:
    void up() { std::cout << "Theater Screen going up" << std::endl; }
    void down() { std::cout << "Theater Screen going down" << std::endl; }
};

#endif

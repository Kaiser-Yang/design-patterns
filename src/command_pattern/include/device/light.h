#ifndef DESIGN_PATTERNS_LIGHT_H
#define DESIGN_PATTERNS_LIGHT_H

#include <iostream>

class Light {
public:
    void on() const {
        std::cout << "Light is on" << std::endl;
    }
    void off() const {
        std::cout << "Light is off" << std::endl;
    }
};

#endif

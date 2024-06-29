#ifndef DESIGN_PATTERN_THEATER_LIGHTS_H
#define DESIGN_PATTERN_THEATER_LIGHTS_H

#include <iostream>

class TheaterLights {
public:
    void on() { std::cout << "Theater Ceiling Lights on" << std::endl; }
    void off() { std::cout << "Theater Ceiling Lights off" << std::endl; }
    void dim(int level) {
        std::cout << "Theater Ceiling Lights dimming to " << level << "%" << std::endl;
    }
};

#endif

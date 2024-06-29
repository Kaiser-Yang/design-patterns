#ifndef DESIGN_PATTERNS_TV_H
#define DESIGN_PATTERNS_TV_H

#include <iostream>

class TV {
public:
    void on() const { std::cout << "TV is on" << std::endl; }
    void off() const { std::cout << "TV is off" << std::endl; }
};

#endif

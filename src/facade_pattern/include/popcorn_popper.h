#ifndef DESIGN_PATTERN_POPCORN_POPPER_H
#define DESIGN_PATTERN_POPCORN_POPPER_H

#include <iostream>

class PopcornPopper {
public:
    void on() { std::cout << "Popcorn Popper on" << std::endl; }
    void off() { std::cout << "Popcorn Popper off" << std::endl; }
    void pop() { std::cout << "Popcorn Popper popping popcorn!" << std::endl; }
};

#endif

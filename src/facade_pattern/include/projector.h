#ifndef DESIGN_PATTERN_PROJECTOR_H
#define DESIGN_PATTERN_PROJECTOR_H

#include <iostream>
#include <memory>

#include "streaming_player.h"
class Projector {
public:
    void on() { std::cout << "Projector on" << std::endl; }
    void off() { std::cout << "Projector off" << std::endl; }
    void wideScreenMode() {
        std::cout << "Projector in widescreen mode (16x9 aspect ratio)" << std::endl;
    }

private:
    std::shared_ptr<StreamingPlayer> player;
};

#endif

#ifndef DESIGN_PATTERN_AMPLIFIER_H
#define DESIGN_PATTERN_AMPLIFIER_H

#include <iostream>
#include <memory>

#include "streaming_player.h"
#include "tuner.h"

class Amplifier {
public:
    void on() { std::cout << "Amplifier on" << std::endl; }
    void off() { std::cout << "Amplifier off" << std::endl; }
    void setStreamPlayer(std::shared_ptr<StreamingPlayer> player) { this->player = player; }
    void setSurroundSound() {
        std::cout << "Amplifier surround sound on (5 speakers, 1 subwoofer)" << std::endl;
    }
    void setVolume(int level) { std::cout << "Amplifier setting volume to " << level << std::endl; }

private:
    std::shared_ptr<Tuner> tuner;
    std::shared_ptr<StreamingPlayer> player;
};

#endif

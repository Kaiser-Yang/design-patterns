#ifndef DESIGN_PATTERN_STREAMING_PLAYER_H
#define DESIGN_PATTERN_STREAMING_PLAYER_H

#include <iostream>
#include <memory>
#include <string>

class Amplifier;

class StreamingPlayer {
public:
    void on() { std::cout << "Streaming Player on" << std::endl; }
    void off() { std::cout << "Streaming Player off" << std::endl; }
    void stop() { std::cout << "Streaming Player stopped" << std::endl; }
    void play(const std::string &movie) {
        std::cout << "Streaming Player playing " << movie << std::endl;
    }

private:
    std::shared_ptr<Amplifier> amplifier;
};

#endif

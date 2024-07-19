#ifndef DESIGN_PATTERN_HOME_THEATER_FACADE_H
#define DESIGN_PATTERN_HOME_THEATER_FACADE_H

#include <iostream>
#include <memory>

#include "amplifier.h"
#include "popcorn_popper.h"
#include "projector.h"
#include "screen.h"
#include "streaming_player.h"
#include "theater_lights.h"
#include "tuner.h"

class HomeTheaterFacade {
public:
    HomeTheaterFacade(std::shared_ptr<Amplifier> amplifier,
                      std::shared_ptr<Tuner> tuner,
                      std::shared_ptr<StreamingPlayer> player,
                      std::shared_ptr<Projector> projector,
                      std::shared_ptr<TheaterLights> lights,
                      std::shared_ptr<Screen> screen,
                      std::shared_ptr<PopcornPopper> poper) {
        this->amplifier = amplifier;
        this->tuner     = tuner;
        this->player    = player;
        this->projector = projector;
        this->lights    = lights;
        this->screen    = screen;
        this->poper     = poper;
    }
    void watchMovie(const std::string &movie) {
        std::cout << "Get ready to watch a movie..." << std::endl;
        poper->on();
        poper->pop();
        lights->dim(10);
        screen->down();
        projector->on();
        projector->wideScreenMode();
        amplifier->on();
        amplifier->setStreamPlayer(player);
        amplifier->setSurroundSound();
        amplifier->setVolume(5);
        player->on();
        player->play(movie);
    }
    void endMovie() {
        std::cout << "Shutting movie theater down..." << std::endl;
        poper->off();
        lights->on();
        screen->up();
        projector->off();
        amplifier->off();
        player->stop();
        player->off();
    }

private:
    std::shared_ptr<Amplifier> amplifier;
    std::shared_ptr<Tuner> tuner;
    std::shared_ptr<StreamingPlayer> player;
    std::shared_ptr<Projector> projector;
    std::shared_ptr<TheaterLights> lights;
    std::shared_ptr<Screen> screen;
    std::shared_ptr<PopcornPopper> poper;
};

#endif

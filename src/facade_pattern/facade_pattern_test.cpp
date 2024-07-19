#include <iostream>
#include <memory>

#include "include/home_theater_facade.h"

void FacadePatternTest() {
    std::shared_ptr<HomeTheaterFacade> homeTheater =
        std::make_shared<HomeTheaterFacade>(std::make_shared<Amplifier>(),
                                            std::make_shared<Tuner>(),
                                            std::make_shared<StreamingPlayer>(),
                                            std::make_shared<Projector>(),
                                            std::make_shared<TheaterLights>(),
                                            std::make_shared<Screen>(),
                                            std::make_shared<PopcornPopper>());
    homeTheater->watchMovie("Raiders of the Lost Ark");
    homeTheater->endMovie();
}

int main() {
    FacadePatternTest();
    return 0;
}

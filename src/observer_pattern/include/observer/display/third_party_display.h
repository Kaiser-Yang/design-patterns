#ifndef DESIGN_PATTERNS_THIRD_PARTY_DISPLAY_H
#define DESIGN_PATTERNS_THIRD_PARTY_DISPLAY_H

#include <iostream>

#include "display_element.h"
#include "observer/observer.h"
#include "subject/weather_data.h"

class ThirdPartyDisplay : public Observer, public DisplayElement {
public:
    ThirdPartyDisplay(WeatherData &weatherData) : weatherData(weatherData) {}

    void update(double temperature, double humidity, double pressure) override {
        // place your code here
        display();
    }

    void update() override {
        // place your code here
        display();
    }

    void display() override {
        // place your code here
        std::cout << "Third party display: \n\n";
    }

private:
    WeatherData &weatherData;
};

#endif

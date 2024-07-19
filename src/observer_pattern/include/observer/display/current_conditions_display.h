#ifndef DESIGN_PATTERNS_CURRENT_CONDITIONS_DISPLAY_H
#define DESIGN_PATTERNS_CURRENT_CONDITIONS_DISPLAY_H

#include <iostream>

#include "display_element.h"
#include "observer/observer.h"
#include "subject/weather_data.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
    CurrentConditionsDisplay(WeatherData &weatherData) : weatherData(weatherData) {}

    // push type
    void update(double temperature, double humidity, double) override {
        this->temperature = temperature;
        this->humidity    = humidity;
        display();
    }

    // pull type
    void update() override {
        this->temperature = weatherData.getTemperature();
        this->humidity    = weatherData.getHumidity();
        display();
    }

    void display() override {
        std::cout << "Current conditions: " << temperature << "F degrees, " << humidity
                  << "% humidity\n\n";
    }

private:
    double temperature = 0;
    double humidity    = 0;
    WeatherData &weatherData;
};

#endif

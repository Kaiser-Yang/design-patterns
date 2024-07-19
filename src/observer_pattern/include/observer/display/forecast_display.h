#ifndef DESIGN_PATTERNS_FORECAST_DISPLAY_H
#define DESIGN_PATTERNS_FORECAST_DISPLAY_H

#include <iostream>

#include "display_element.h"
#include "observer/observer.h"
#include "subject/weather_data.h"

class ForecastDisplay : public Observer, public DisplayElement {
public:
    ForecastDisplay(WeatherData &weatherData) : weatherData(weatherData) {}

    // push type
    void update(double temperature, double humidity, double pressure) override {
        lastTemperature = currentTemperature;

        currentTemperature = temperature;

        display();
    }

    // pull type
    void update() override {
        lastTemperature = currentTemperature;

        currentTemperature = weatherData.getTemperature();

        display();
    }

    void display() override {
        std::cout << "Forecast: ";
        if (currentTemperature > lastTemperature) {
            std::cout << "Improving weather on the way.\n";
        } else if (currentTemperature == lastTemperature) {
            std::cout << "More of the same.\n";
        } else {
            std::cout << "Watch out for cooler, rainy weather.\n";
        }
        std::cout << "\n";
    }

private:
    double currentTemperature = 0;
    double lastTemperature    = 0;
    WeatherData &weatherData;
};

#endif

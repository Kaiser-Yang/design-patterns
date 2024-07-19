#ifndef DESIGN_PATTERNS_STATISTICS_DISPLAY_H
#define DESIGN_PATTERNS_STATISTICS_DISPLAY_H

#include <iostream>
#include <limits>

#include "display_element.h"
#include "observer/observer.h"
#include "subject/weather_data.h"

class StatisticsDisplay : public Observer, public DisplayElement {
public:
    StatisticsDisplay(WeatherData &weatherData) : weatherData(weatherData) {}

    // push type
    void update(double temperature, double humidity, double pressure) override {
        cnt++;

        avgTemperature += (temperature - avgTemperature) / cnt;
        avgHumidity += (humidity - avgHumidity) / cnt;
        avgPressure += (pressure - avgPressure) / cnt;

        minTemperature = std::min(minTemperature, temperature);
        minHumidity    = std::min(minHumidity, humidity);
        minPressure    = std::min(minPressure, pressure);

        maxTemperature = std::max(maxTemperature, temperature);
        maxHumidity    = std::max(maxHumidity, humidity);
        maxPressure    = std::max(maxPressure, pressure);

        display();
    }

    // pull type
    void update() override {
        double temperature = weatherData.getTemperature();
        double humidity    = weatherData.getHumidity();
        double pressure    = weatherData.getPressure();

        cnt++;

        avgTemperature += (temperature - avgTemperature) / cnt;
        avgHumidity += (humidity - avgHumidity) / cnt;
        avgPressure += (pressure - avgPressure) / cnt;

        minTemperature = std::min(minTemperature, temperature);
        minHumidity    = std::min(minHumidity, humidity);
        minPressure    = std::min(minPressure, pressure);

        maxTemperature = std::max(maxTemperature, temperature);
        maxHumidity    = std::max(maxHumidity, humidity);
        maxPressure    = std::max(maxPressure, pressure);

        display();
    }

    // display the average, min and max measurements
    void display() override {
        std::cout << "Avg/Max/Min temperature = " << avgTemperature << "/" << maxTemperature << "/"
                  << minTemperature << "\n";
        std::cout << "Avg/Max/Min humidity = " << avgHumidity << "/" << maxHumidity << "/"
                  << minHumidity << "\n";
        std::cout << "Avg/Max/Min pressure = " << avgPressure << "/" << maxPressure << "/"
                  << minPressure << "\n";
        std::cout << "\n";
    }

private:
    size_t cnt            = 0;
    double minTemperature = std::numeric_limits<double>::max(),
           maxTemperature = std::numeric_limits<double>::min(), avgTemperature = 0;
    double minHumidity = std::numeric_limits<double>::max(),
           maxHumidity = std::numeric_limits<double>::min(), avgHumidity = 0;
    double minPressure = std::numeric_limits<double>::max(),
           maxPressure = std::numeric_limits<double>::min(), avgPressure = 0;
    WeatherData &weatherData;
};

#endif

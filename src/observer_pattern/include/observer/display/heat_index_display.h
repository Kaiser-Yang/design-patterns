#ifndef DESIGN_PATTERNS_HEAT_INDEX_DISPLAY_H
#define DESIGN_PATTERNS_HEAT_INDEX_DISPLAY_H

#include <iostream>

#include "display_element.h"
#include "observer/observer.h"
#include "subject/weather_data.h"

class HeatIndexDisplay : public Observer, public DisplayElement {
public:
    HeatIndexDisplay(WeatherData &weatherData) : weatherData(weatherData) {}

    // push type
    void update(double t, double rh, double) override {
        index = (double)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
                          (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
                          (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
                          (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) +
                          (0.0000291583 * (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
                          (0.000000197483 * (t * rh * rh * rh)) -
                          (0.0000000218429 * (t * t * t * rh * rh)) +
                          0.000000000843296 * (t * t * rh * rh * rh)) -
                         (0.0000000000481975 * (t * t * t * rh * rh * rh)));
        display();
    }

    // pull type
    void update() override {
        double t  = weatherData.getTemperature();
        double rh = weatherData.getHumidity();
        index     = (double)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
                          (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
                          (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
                          (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) +
                          (0.0000291583 * (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
                          (0.000000197483 * (t * rh * rh * rh)) -
                          (0.0000000218429 * (t * t * t * rh * rh)) +
                          0.000000000843296 * (t * t * rh * rh * rh)) -
                         (0.0000000000481975 * (t * t * t * rh * rh * rh)));
        display();
    }

    void display() override { std::cout << "Heat index is " << index << "\n\n"; }

private:
    double index = 0;
    WeatherData &weatherData;
};

#endif

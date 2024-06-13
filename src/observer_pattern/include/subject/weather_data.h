#ifndef DESIGN_PATTERNS_WEATHER_DATA_H
#define DESIGN_PATTERNS_WEATHER_DATA_H

#include "subject.h"

class WeatherData : public Subject {
public:
    WeatherData() = default;

    void notifyObservers() override {
        for (auto observer : observers) {
            // push
            // observer->update(temperature, humidity, pressure);
            // pull
            observer->update();
        }
    }

    void measurementsChanged() { notifyObservers(); }

    void setMeasurements(float temperature, float humidity, float pressure) {
        if (this->temperature == temperature && this->humidity == humidity &&
            this->pressure == pressure) {
            return;
        }
        this->temperature = temperature;
        this->humidity    = humidity;
        this->pressure    = pressure;
        measurementsChanged();
    }

    double getTemperature() const { return temperature; }

    double getHumidity() const { return humidity; }

    double getPressure() const { return pressure; }

    void setTemperature(double temperature) {
        if (this->temperature == temperature) { return; }
        this->temperature = temperature;
        measurementsChanged();
    }

    void setHumidity(double humidity) {
        if (this->humidity == humidity) { return; }
        this->humidity = humidity;
        measurementsChanged();
    }

    void setPressure(double pressure) {
        if (this->pressure == pressure) { return; }
        this->pressure = pressure;
        measurementsChanged();
    }

private:
    double temperature;
    double humidity;
    double pressure;
};

#endif

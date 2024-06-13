#include <memory>
#include <vector>

#include "observer/display/current_conditions_display.h"
#include "observer/display/forecast_display.h"
#include "observer/display/heat_index_display.h"
#include "observer/display/statistics_display.h"
#include "observer/display/third_party_display.h"
#include "subject/weather_data.h"

void ObserverPatternTest() {
    WeatherData subject;

    std::vector<std::shared_ptr<Observer>> observers;

    observers.push_back(std::make_shared<CurrentConditionsDisplay>(subject));
    observers.push_back(std::make_shared<ForecastDisplay>(subject));
    observers.push_back(std::make_shared<StatisticsDisplay>(subject));
    observers.push_back(std::make_shared<ThirdPartyDisplay>(subject));
    observers.push_back(std::make_shared<HeatIndexDisplay>(subject));

    for (const auto &observer : observers) { subject.registerObserver(observer); }

    // we must do this to simulate the changes
    subject.setMeasurements(80, 65, 30.4);
    subject.setMeasurements(82, 70, 29.2);
    subject.setMeasurements(78, 90, 29.2);

    while (!observers.empty()) {
        subject.registerObserver(observers.back());
        observers.pop_back();
    }
}

int main() {
    ObserverPatternTest();
    return 0;
}

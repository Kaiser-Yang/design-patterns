#ifndef DESIGN_PATTERNS_OBSERVABLE_H
#define DESIGN_PATTERNS_OBSERVABLE_H

#include <memory>
#include <vector>

#include "observer.h"
#include "quack_observable.h"

class Observable : public QuackObservable {
public:
    Observable(std::shared_ptr<QuackObservable> duck) : duck(duck) {}

    void registerObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void notifyObservers() override {
        for (auto observer : observers) {
            observer->update(duck);
        }
    }

private:
    std::shared_ptr<QuackObservable> duck;
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif

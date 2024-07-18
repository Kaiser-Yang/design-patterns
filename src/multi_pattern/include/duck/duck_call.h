#ifndef DESIGN_PATTERNS_DUCK_CALL_H
#define DESIGN_PATTERNS_DUCK_CALL_H

#include <iostream>

#include "observer/observable.h"
#include "quackable.h"

class DuckCall : public Quackable, public std::enable_shared_from_this<DuckCall> {
public:
    void init() {
        name = "Duck Call";
        observable = std::make_shared<Observable>(shared_from_this());
    }

    void quack() override {
        std::cout << "Kwak" << std::endl;
    }

    void registerObserver(std::shared_ptr<Observer> observer) override {
        observable->registerObserver(observer);
    }

    void notifyObservers() override {
        observable->notifyObservers();
    }

private:
    std::shared_ptr<Observable> observable;
};

#endif

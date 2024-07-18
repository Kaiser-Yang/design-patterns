#ifndef DESIGN_PATTERNS_REDHEAD_DUCK_H
#define DESIGN_PATTERNS_REDHEAD_DUCK_H

#include <iostream>

#include "observer/observable.h"
#include "quackable.h"

class RedheadDuck : public Quackable, public std::enable_shared_from_this<RedheadDuck> {
public:
    void init() {
        name = "Redhead Duck";
        observable = std::make_shared<Observable>(shared_from_this());
    }

    void quack() override {
        std::cout << "Quack" << std::endl;
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

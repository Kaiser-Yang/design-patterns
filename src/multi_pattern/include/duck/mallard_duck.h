#ifndef DESIGN_PATTERNS_MALLARD_DUCK_H
#define DESIGN_PATTERNS_MALLARD_DUCK_H

#include <iostream>
#include <memory>

#include "observer/observable.h"
#include "quackable.h"

class MallardDuck : public Quackable, public std::enable_shared_from_this<MallardDuck> {
public:
    void init() {
        name = "Mallard Duck";
        observable = std::make_shared<Observable>(shared_from_this());
    }

    void quack() override {
        std::cout << "Quack" << std::endl;
        notifyObservers();
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

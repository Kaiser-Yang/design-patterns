#ifndef DESIGN_PATTERNS_QUACK_COUNTER_H
#define DESIGN_PATTERNS_QUACK_COUNTER_H

#include <memory>

#include "observer/observable.h"
#include "quackable.h"

class QuackCounter : public Quackable, public std::enable_shared_from_this<QuackCounter> {
public:
    QuackCounter(std::shared_ptr<Quackable> duck) : duck(duck) {}

    void quack() override {
        duck->quack();
        ++quacks;
    }

    static int getQuacks() {
        return quacks;
    }

    void registerObserver(std::shared_ptr<Observer> observer) override {
        duck->registerObserver(observer);
    }

    void notifyObservers() override {
        duck->notifyObservers();
    }

private:
    void init() {
        observable = std::make_shared<Observable>(shared_from_this());
    }

    std::shared_ptr<Observable> observable;
    std::shared_ptr<Quackable> duck;
    static size_t quacks;
};


#endif

#ifndef DESIGN_PATTERNS_FLOCK_H
#define DESIGN_PATTERNS_FLOCK_H

#include <memory>
#include <vector>

#include "observer/observable.h"
#include "quackable.h"

class Flock : public Quackable, public std::enable_shared_from_this<Flock> {
public:
    void init() {
        name = "A flock of ducks";
        observable = std::make_shared<Observable>(shared_from_this());
    }

    void add(std::shared_ptr<Quackable> quackable) {
        quackables.push_back(quackable);
    }

    void quack() override {
        for (auto quackable : quackables) {
            quackable->quack();
        }
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
    std::vector<std::shared_ptr<Quackable>> quackables;
};

#endif

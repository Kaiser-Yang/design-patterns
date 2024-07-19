#ifndef DESIGN_INCLUDE_ADAPTER_GOOSE_ADAPTER_H
#define DESIGN_INCLUDE_ADAPTER_GOOSE_ADAPTER_H

#include <memory>

#include "observer/observable.h"
#include "quackable.h"
#include "goose.h"

class GooseAdapter : public Quackable, public std::enable_shared_from_this<GooseAdapter> {
public:
    explicit GooseAdapter(std::shared_ptr<Goose> goose) : goose(goose) {  }

    void quack() override {
        goose->honk();
    }

    void registerObserver(std::shared_ptr<Observer> observer) override {
        observable->registerObserver(observer);
    }

    void notifyObservers() override {
        observable->notifyObservers();
    }

    void init() {
        name = "Goose pretending to be a Duck";
        observable = std::make_shared<Observable>(shared_from_this());
    }

private:
    std::shared_ptr<Observable> observable;
    std::shared_ptr<Goose> goose;
};

#endif


#ifndef DESIGN_PATTERNS_COUNTING_DUCK_FACTORY_H
#define DESIGN_PATTERNS_COUNTING_DUCK_FACTORY_H

#include <memory>

#include "abstract_factory.h"
#include "adapter/goose_adapter.h"
#include "composite/flock.h"
#include "counter/quack_counter.h"
#include "duck/duck_call.h"
#include "duck/mallard_duck.h"
#include "duck/redhead_duck.h"
#include "duck/rubber_duck.h"

class CountingDuckFactory : public AbstractFactory {
public:
    std::shared_ptr<Quackable> createMallardDuck() override {
        auto duck = std::make_shared<MallardDuck>();
        duck->init();
        return std::make_shared<QuackCounter>(duck);
    }

    std::shared_ptr<Quackable> createRedheadDuck() override {
        auto duck = std::make_shared<RedheadDuck>();
        duck->init();
        return std::make_shared<QuackCounter>(duck);
    }

    std::shared_ptr<Quackable> createDuckCall() override {
        auto duck = std::make_shared<DuckCall>();
        duck->init();
        return std::make_shared<QuackCounter>(duck);
    }

    std::shared_ptr<Quackable> createRubberDuck() override {
        auto duck = std::make_shared<RubberDuck>();
        duck->init();
        return std::make_shared<QuackCounter>(duck);
    }

    std::shared_ptr<Quackable> createGooseAdapter() override {
        auto duck = std::make_shared<GooseAdapter>(std::make_shared<Goose>());
        duck->init();
        return std::make_shared<QuackCounter>(duck);
    }

};

#endif

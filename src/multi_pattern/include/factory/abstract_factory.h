#ifndef DESIGN_PATTERNS_ABSTRACT_FACTORY_H
#define DESIGN_PATTERNS_ABSTRACT_FACTORY_H

#include <memory>

#include "quackable.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<Quackable> createMallardDuck() = 0;
    virtual std::shared_ptr<Quackable> createRedheadDuck() = 0;
    virtual std::shared_ptr<Quackable> createDuckCall() = 0;
    virtual std::shared_ptr<Quackable> createRubberDuck() = 0;
    virtual std::shared_ptr<Quackable> createGooseAdapter() = 0;
    virtual ~AbstractFactory() = default;
};

#endif

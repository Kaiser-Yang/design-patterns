#ifndef DESIGN_PATTERNS_FACTORY_METHOD_H
#define DESIGN_PATTERNS_FACTORY_METHOD_H

#include <memory>
#include "composite/flock.h"

class FactoryMethod {
public:
    static std::shared_ptr<Flock> createFlock() {
        auto flock = std::make_shared<Flock>();
        flock->init();
        return flock;
    }
};

#endif

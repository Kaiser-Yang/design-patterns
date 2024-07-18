#ifndef DESIGN_PATTERNS_QUACKOLOGIST_H
#define DESIGN_PATTERNS_QUACKOLOGIST_H

#include <iostream>
#include "observer/observer.h"


class Quackologist : public Observer {
public:
    void update(std::shared_ptr<QuackObservable> duck) override {
        std::cout << "Quackologist: " << duck->getName() << " just quacked\n";
    }
};

#endif

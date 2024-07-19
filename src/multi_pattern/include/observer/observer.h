#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

#include "observer/quack_observable.h"

class Observer {
public:
    virtual void update(std::shared_ptr<QuackObservable> duck) = 0;
};

#endif

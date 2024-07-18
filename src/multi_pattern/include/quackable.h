#ifndef DESIGN_PATTERNS_QUACKABLE_H
#define DESIGN_PATTERNS_QUACKABLE_H

#include "observer/quack_observable.h"

class Quackable : public QuackObservable {
public:
    virtual void quack() = 0;
};

#endif

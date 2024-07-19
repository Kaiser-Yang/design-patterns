#ifndef DESIGN_PATTERNS_DECAF_H
#define DESIGN_PATTERNS_DECAF_H

#include "beverage.h"

class Decaf : public Beverage {
public:
    Decaf() { description = "Decaf Coffee"; }
    double cost() const override { return 1.05; }
};

#endif

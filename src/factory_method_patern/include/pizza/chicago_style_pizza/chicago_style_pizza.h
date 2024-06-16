#ifndef DESIGN_PATTERNS_CHICAGO_STYLE_PIZZA_H
#define DESIGN_PATTERNS_CHICAGO_STYLE_PIZZA_H

#include "pizza/pizza.h"

class ChicagoStylePizza : public Pizza {
public:
    void cut() override { std::cout << "Cutting the pizza into square slices" << std::endl; }
};

#endif

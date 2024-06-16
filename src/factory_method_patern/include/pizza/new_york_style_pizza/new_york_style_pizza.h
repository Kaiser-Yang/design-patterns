#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_H

#include "pizza/pizza.h"

class NewYorkStylePizza : public Pizza {
public:
    void cut() override { std::cout << "Cutting the pizza into triangle slices" << std::endl; }
};

#endif

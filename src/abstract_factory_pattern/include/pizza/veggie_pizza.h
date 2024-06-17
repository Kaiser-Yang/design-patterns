#ifndef DESIGN_PATTERNS_VEGGIE_PIZZA_H
#define DESIGN_PATTERNS_VEGGIE_PIZZA_H

#include <memory>

#include "pizza.h"

class VeggiePizza : public Pizza {
public:
    VeggiePizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : Pizza(std::move(ingredientFactory)) {}
};

#endif

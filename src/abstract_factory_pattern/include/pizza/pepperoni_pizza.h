#ifndef DESIGN_PATTERNS_PEPPERONI_PIZZA_H
#define DESIGN_PATTERNS_PEPPERONI_PIZZA_H

#include <memory>

#include "ingredient/other/pepperoni.h"
#include "pizza.h"

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : Pizza(std::move(ingredientFactory)) {}
};

#endif

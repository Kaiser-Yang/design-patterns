#ifndef DESIGN_PATTERNS_CHEESE_PIZZA_H
#define DESIGN_PATTERNS_CHEESE_PIZZA_H

#include <memory>

#include "factory/pizza_ingredient_factory.h"
#include "pizza.h"

class CheesePizza : public Pizza {
public:
    CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : Pizza(std::move(ingredientFactory)) {
    }
};

#endif

#ifndef DESIGN_PATTERNS_CLAM_PIZZA_H
#define DESIGN_PATTERNS_CLAM_PIZZA_H

#include <memory>

#include "factory/pizza_ingredient_factory.h"
#include "pizza.h"

class ClamPizza : public Pizza {
public:
    ClamPizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : Pizza(std::move(ingredientFactory)) {}
};

#endif

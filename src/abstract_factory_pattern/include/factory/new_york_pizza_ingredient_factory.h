#ifndef DESIGN_PATTERNS_NEW_YORK_PIZZA_INGREDIENT_FACTORY_H
#define DESIGN_PATTERNS_NEW_YORK_PIZZA_INGREDIENT_FACTORY_H

#include <iostream>

#include "factory/pizza_ingredient_factory.h"
#include "ingredient/cheese/cheese.h"
#include "ingredient/cheese/reggiano_cheese.h"
#include "ingredient/clam/clam.h"
#include "ingredient/clam/fresh_clam.h"
#include "ingredient/dough/thin_crust_dough.h"
#include "ingredient/sauce/marinara_sauce.h"

class NewYorkPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough createDough() override {
        std::cout << "Creating thin crust dough" << std::endl;
        return ThinCrustDough();
    }

    Sauce createSauce() override {
        std::cout << "Creating marinara sauce" << std::endl;
        return MarinaraSauce();
    }

    Cheese createCheese() override {
        std::cout << "Creating reggiano cheese" << std::endl;
        return ReggianoCheese();
    }

    Clam createClam() override {
        std::cout << "Creating fresh clam" << std::endl;
        return FreshClam();
    }
};

#endif

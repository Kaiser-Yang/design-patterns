#ifndef DESIGN_PATTERNS_CHICAGO_PIZZA_INGREDIENT_FACTORY_H
#define DESIGN_PATTERNS_CHICAGO_PIZZA_INGREDIENT_FACTORY_H

#include "ingredient/cheese/mozzarella_cheese.h"
#include "ingredient/clam/frozen_clam.h"
#include "ingredient/dough/thick_crust_dough.h"
#include "ingredient/sauce/plum_tomato_sauce.h"
#include "factory/pizza_ingredient_factory.h"

#include <iostream>

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    Dough createDough() override {
        std::cout << "Creating thick crust dough" << std::endl;
        return ThickCrustDough();
    }

    Sauce createSauce() override {
        std::cout << "Creating plum tomato sauce" << std::endl;
        return PlumTomatoSauce();
    }

    Cheese createCheese() override {
        std::cout << "Creating mozzarella cheese" << std::endl;
        return MozzarellaCheese();
    }

    Clam createClam() override {
        std::cout << "Creating frozen clam" << std::endl;
        return FrozenClam();
    }
};

#endif

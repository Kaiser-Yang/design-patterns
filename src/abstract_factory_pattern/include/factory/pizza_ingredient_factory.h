#ifndef DESIGN_PATTERNS_PIZZA_INGREDIENT_FACTORY_H
#define DESIGN_PATTERNS_PIZZA_INGREDIENT_FACTORY_H

#include <iostream>

#include "ingredient/cheese/cheese.h"
#include "ingredient/clam/clam.h"
#include "ingredient/dough/dough.h"
#include "ingredient/other/pepperoni.h"
#include "ingredient/other/veggie.h"
#include "ingredient/sauce/sauce.h"

class PizzaIngredientFactory {
public:
    virtual Dough createDough()   = 0;
    virtual Sauce createSauce()   = 0;
    virtual Cheese createCheese() = 0;
    virtual Clam createClam()     = 0;
    Pepperoni createPepperoni() {
        std::cout << "Creating pepperoni" << std::endl;
        return Pepperoni();
    }
    Veggie createVeggie() {
        std::cout << "Creating veggie" << std::endl;
        return Veggie();
    }
};

#endif

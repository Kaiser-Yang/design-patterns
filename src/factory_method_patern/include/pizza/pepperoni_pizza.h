#ifndef DESIGN_PATTERNS_PEPPERONI_PIZZA_H
#define DESIGN_PATTERNS_PEPPERONI_PIZZA_H

#include "pizza.h"

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza() {
        name  = "Pepperoni Pizza";
        dough = "Crust";
        sauce = "Marinara sauce";
        toppings.push_back("Sliced Pepperoni");
        toppings.push_back("Sliced Onion");
        toppings.push_back("Grated parmesan cheese");
    }
};

#endif

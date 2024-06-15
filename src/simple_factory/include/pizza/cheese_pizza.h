#ifndef DESIGN_PATTERNS_CHEESE_PIZZA_H
#define DESIGN_PATTERNS_CHEESE_PIZZA_H

#include "pizza.h"

class CheesePizza : public Pizza {
public:
    CheesePizza() {
        name = "Cheese Pizza";
        dough = "Regular Crust";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Fresh Mozzarella");
        toppings.push_back("Parmesan");
    }
};

#endif

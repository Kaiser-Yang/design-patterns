#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_CHEESE_PIZZA_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_CHEESE_PIZZA_H

#include "new_york_style_pizza.h"

class NewYorkStyleCheesePizza : public NewYorkStylePizza {
public:
    NewYorkStyleCheesePizza() {
        name  = "New York Style Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};

#endif

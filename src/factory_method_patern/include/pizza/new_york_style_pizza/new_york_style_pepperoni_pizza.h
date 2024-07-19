#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_PEPPERONI_PIZZA_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_PEPPERONI_PIZZA_H

#include "new_york_style_pizza.h"

class NewYorkStylePepperoniPizza : public NewYorkStylePizza {
public:
    NewYorkStylePepperoniPizza() {
        name  = "New York Style Pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Pepperoni");
        toppings.push_back("Grated Reggiano Cheese");
    }
};

#endif

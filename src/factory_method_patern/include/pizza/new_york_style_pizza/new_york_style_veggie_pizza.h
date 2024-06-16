#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_VEGGIE_PIZZA_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_VEGGIE_PIZZA_H

#include "new_york_style_pizza.h"

class NewYorkStyleVeggiePizza : public NewYorkStylePizza {
public:
    NewYorkStyleVeggiePizza() {
        name  = "New York Style Veggie Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Grated Reggiano Cheese");
        toppings.push_back("Garlic");
        toppings.push_back("Onion");
        toppings.push_back("Mushrooms");
        toppings.push_back("Red Pepper");
    }
};

#endif

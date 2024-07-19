#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_CLAM_PIZZA_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_CLAM_PIZZA_H

#include "new_york_style_pizza.h"

class NewYorkStyleClamPizza : public NewYorkStylePizza {
public:
    NewYorkStyleClamPizza() {
        name  = "New York Style Clam Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Clams");
        toppings.push_back("Grated Reggiano Cheese");
    }
};

#endif

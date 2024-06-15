#ifndef DESIGN_PATTERNS_CLAM_PIZZA_H
#define DESIGN_PATTERNS_CLAM_PIZZA_H

#include "pizza.h"

class ClamPizza : public Pizza {
public:
    ClamPizza() {
        name = "Clam Pizza";
        dough = "Thin crust";
        sauce = "White garlic sauce";
        toppings.push_back("Clams");
        toppings.push_back("Grated parmesan cheese");
    }
};

#endif

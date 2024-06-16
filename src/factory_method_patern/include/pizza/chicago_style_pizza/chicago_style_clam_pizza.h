#ifndef DESIGN_PATTERNS_CHICAGO_STYLE_CLAM_PIZZA_H
#define DESIGN_PATTERNS_CHICAGO_STYLE_CLAM_PIZZA_H

#include "chicago_style_pizza.h"

class ChicagoStyleClamPizza : public ChicagoStylePizza {
public:
    ChicagoStyleClamPizza() {
        name  = "Chicago Style Deep Dish Clam Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
        toppings.push_back("Frozen Clams from Chesapeake Bay");
    }
};

#endif

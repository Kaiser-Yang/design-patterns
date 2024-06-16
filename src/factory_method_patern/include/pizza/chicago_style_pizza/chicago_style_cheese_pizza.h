#ifndef DESIGN_PATTERNS_CHICAGO_STYLE_CHEESE_PIZZA_H
#define DESIGN_PATTERNS_CHICAGO_STYLE_CHEESE_PIZZA_H

#include "chicago_style_pizza.h"

class ChicagoStyleCheesePizza : public ChicagoStylePizza {
public:
    ChicagoStyleCheesePizza() {
        name  = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
    }
};

#endif

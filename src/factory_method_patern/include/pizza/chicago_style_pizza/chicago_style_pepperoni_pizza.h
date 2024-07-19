#ifndef DESIGN_PATTERNS_CHICAGO_STYLE_PEPPERONI_PIZZA_H
#define DESIGN_PATTERNS_CHICAGO_STYLE_PEPPERONI_PIZZA_H

#include "chicago_style_pizza.h"

class ChicagoStylePepperoniPizza : public ChicagoStylePizza {
public:
    ChicagoStylePepperoniPizza() {
        name  = "Chicago Style Deep Dish Pepperoni Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
        toppings.push_back("Black Olives");
        toppings.push_back("Spinach");
        toppings.push_back("Eggplant");
        toppings.push_back("Sliced Pepperoni");
    }
};

#endif

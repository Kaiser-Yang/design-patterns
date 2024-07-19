#ifndef DESIGN_PATTERNS_CHICAGO_STYLE_VEGGIE_PIZZA_H
#define DESIGN_PATTERNS_CHICAGO_STYLE_VEGGIE_PIZZA_H

#include "chicago_style_pizza.h"

class ChicagoStyleVeggiePizza : public ChicagoStylePizza {
public:
    ChicagoStyleVeggiePizza() {
        name  = "Chicago Deep Dish Veggie Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        toppings.push_back("Shredded Mozzarella Cheese");
        toppings.push_back("Black Olives");
        toppings.push_back("Spinach");
        toppings.push_back("Eggplant");
    }
};

#endif

#ifndef DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H
#define DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H

#include "pizza/chicago_style_pizza/chicago_style_cheese_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_clam_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_pepperoni_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_veggie_pizza.h"
#include "pizza/pizza.h"
#include "pizza_store.h"

class ChicagoStylePizzaStore : public PizzaStore {
protected:
    Pizza createPizza(const std::string &type) override {
        Pizza pizza;
        if (type == "cheese") {
            pizza = ChicagoStyleCheesePizza();
        } else if (type == "pepperoni") {
            pizza = ChicagoStylePepperoniPizza();
        } else if (type == "clam") {
            pizza = ChicagoStyleClamPizza();
        } else if (type == "veggie") {
            pizza = ChicagoStyleVeggiePizza();
        }
        return pizza;
    }
};

#endif

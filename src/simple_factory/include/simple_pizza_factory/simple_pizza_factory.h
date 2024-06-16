#ifndef DESIGN_PATTERNS_SIMPLE_PIZZA_FACTORY_H
#define DESIGN_PATTERNS_SIMPLE_PIZZA_FACTORY_H

#include "pizza/cheese_pizza.h"
#include "pizza/clam_pizza.h"
#include "pizza/pepperoni_pizza.h"
#include "pizza/pizza.h"
#include "pizza/veggie_pizza.h"

class SimplePizzaFactory {
public:
    static Pizza createPizza(const std::string &type) {
        Pizza pizza;
        if (type == "cheese") {
            pizza = CheesePizza();
        } else if (type == "pepperoni") {
            pizza = PepperoniPizza();
        } else if (type == "clam") {
            pizza = ClamPizza();
        } else if (type == "veggie") {
            pizza = VeggiePizza();
        }
        return pizza;
    }
};

#endif

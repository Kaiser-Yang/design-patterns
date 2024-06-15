#ifndef DESIGN_PATTERNS_PIZZA_STORE_H
#define DESIGN_PATTERNS_PIZZA_STORE_H

#include "pizza/pizza.h"
#include "simple_pizza_factory/simple_pizza_factory.h"
#include <string>

class PizzaStore {
public:
    Pizza orderPizza(std::string type) {
        Pizza pizza = SimplePizzaFactory::createPizza(type);
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        return pizza;
    }
};

#endif

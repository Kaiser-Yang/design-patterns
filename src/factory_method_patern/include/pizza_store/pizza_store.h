#ifndef DESIGN_PATTERNS_PIZZA_STORE_H
#define DESIGN_PATTERNS_PIZZA_STORE_H

#include <string>

#include "pizza/pizza.h"

class PizzaStore {
public:
    Pizza orderPizza(const std::string &type) {
        Pizza pizza = createPizza(type);
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        return pizza;
    }

    inline virtual ~PizzaStore() = default;

protected:
    virtual Pizza createPizza(const std::string &type) = 0;
};

#endif

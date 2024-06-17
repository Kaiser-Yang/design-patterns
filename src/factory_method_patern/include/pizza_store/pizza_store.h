#ifndef DESIGN_PATTERNS_PIZZA_STORE_H
#define DESIGN_PATTERNS_PIZZA_STORE_H

#include <memory>
#include <string>

#include "pizza/pizza.h"

class PizzaStore {
public:
    std::unique_ptr<Pizza> orderPizza(const std::string &type) {
        std::unique_ptr<Pizza> pizza = createPizza(type);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    inline virtual ~PizzaStore() = default;

protected:
    virtual std::unique_ptr<Pizza> createPizza(const std::string &type) = 0;
};

#endif

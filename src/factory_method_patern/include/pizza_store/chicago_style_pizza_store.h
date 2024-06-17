#ifndef DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H
#define DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H

#include <memory>
#include "pizza/chicago_style_pizza/chicago_style_cheese_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_clam_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_pepperoni_pizza.h"
#include "pizza/chicago_style_pizza/chicago_style_veggie_pizza.h"
#include "pizza/pizza.h"
#include "pizza_store.h"

class ChicagoStylePizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string &type) override {
        std::unique_ptr<Pizza> pizza;
        if (type == "cheese") {
            pizza = std::make_unique<ChicagoStyleCheesePizza>();
        } else if (type == "pepperoni") {
            pizza = std::make_unique<ChicagoStylePepperoniPizza>();
        } else if (type == "clam") {
            pizza = std::make_unique<ChicagoStyleClamPizza>();
        } else if (type == "veggie") {
            pizza = std::make_unique<ChicagoStyleVeggiePizza>();
        }
        return pizza;
    }
};

#endif

#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_STORE_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_STORE_H

#include "pizza/new_york_style_pizza/new_york_style_cheese_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_clam_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_pepperoni_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_veggie_pizza.h"
#include "pizza/pizza.h"
#include "pizza_store.h"

class NewYorkStylePizzaStore : public PizzaStore {
public:
    Pizza createPizza(const std::string &type) override {
        Pizza pizza;
        if (type == "cheese") {
            pizza = NewYorkStyleCheesePizza();
        } else if (type == "pepperoni") {
            pizza = NewYorkStylePepperoniPizza();
        } else if (type == "clam") {
            pizza = NewYorkStyleClamPizza();
        } else if (type == "veggie") {
            pizza = NewYorkStyleVeggiePizza();
        }
        return pizza;
    }
};

#endif

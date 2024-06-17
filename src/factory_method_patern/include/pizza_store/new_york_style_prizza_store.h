#ifndef DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_STORE_H
#define DESIGN_PATTERNS_NEW_YORK_STYLE_PIZZA_STORE_H

#include <memory>

#include "pizza/new_york_style_pizza/new_york_style_cheese_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_clam_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_pepperoni_pizza.h"
#include "pizza/new_york_style_pizza/new_york_style_veggie_pizza.h"
#include "pizza/pizza.h"
#include "pizza_store.h"

class NewYorkStylePizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string &type) override {
        std::unique_ptr<Pizza> pizza;
        if (type == "cheese") {
            pizza = std::make_unique<NewYorkStyleCheesePizza>();
        } else if (type == "pepperoni") {
            pizza = std::make_unique<NewYorkStylePepperoniPizza>();
        } else if (type == "clam") {
            pizza = std::make_unique<NewYorkStyleClamPizza>();
        } else if (type == "veggie") {
            pizza = std::make_unique<NewYorkStyleVeggiePizza>();
        }
        return pizza;
    }
};

#endif

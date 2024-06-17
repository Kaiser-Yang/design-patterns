#ifndef DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H
#define DESIGN_PATTERNS_FACTORY_METHOD_CHICAGO_STYLE_PIZZA_STORE_H

#include <memory>

#include "factory/chicago_pizza_ingredient_factory.h"
#include "pizza/cheese_pizza.h"
#include "pizza/clam_pizza.h"
#include "pizza/pepperoni_pizza.h"
#include "pizza/pizza.h"
#include "pizza/veggie_pizza.h"
#include "pizza_store.h"

class ChicagoStylePizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string &type) override {
        std::unique_ptr<Pizza> pizza;
        if (type == "cheese") {
            pizza =
                std::make_unique<CheesePizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
            pizza->setName("Chicago Style Cheese Pizza");
        } else if (type == "pepperoni") {
            pizza =
                std::make_unique<PepperoniPizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
            pizza->setName("Chicago Style Pepperoni Pizza");
        } else if (type == "clam") {
            pizza = std::make_unique<ClamPizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
            pizza->setName("Chicago Style Clam Pizza");
        } else if (type == "veggie") {
            pizza =
                std::make_unique<VeggiePizza>(std::make_unique<ChicagoPizzaIngredientFactory>());
            pizza->setName("Chicago Style Veggie Pizza");
        }
        return pizza;
    }
};

#endif

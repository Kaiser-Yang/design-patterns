#ifndef DESIGN_PATTERNS_PIZZA_H
#define DESIGN_PATTERNS_PIZZA_H

#include <iostream>
#include <memory>
#include <string>

#include "factory/pizza_ingredient_factory.h"
#include "ingredient/cheese/cheese.h"
#include "ingredient/clam/clam.h"
#include "ingredient/dough/dough.h"
#include "ingredient/other/pepperoni.h"
#include "ingredient/other/veggie.h"
#include "ingredient/sauce/sauce.h"

class Pizza {
public:
    Pizza() = default;
    Pizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : ingredientFactory(std::move(ingredientFactory)) {}
    void bake() { std::cout << "Bake for 25 minutes at 350" << std::endl; }
    void cut() { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
    void box() { std::cout << "Place pizza in official PizzaStore box" << std::endl; }
    void setName(const std::string &name) { this->name = name; }
    void setName(std::string &&name) { this->name = std::move(name); }
    const std::string &getName() const { return name; }
    void prepare() {
        std::cout << "Preparing " << name << std::endl;
        dough  = ingredientFactory->createDough();
        sauce  = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        veggie = ingredientFactory->createVeggie();
    }
    virtual ~Pizza() = default;

protected:
    std::string name;
    Cheese cheese;
    Clam clam;
    Dough dough;
    Sauce sauce;
    Pepperoni pepperoni;
    Veggie veggie;

private:
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory;
};

#endif

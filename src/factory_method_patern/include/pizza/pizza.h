#ifndef DESIGN_PATTERNS_PIZZA_H
#define DESIGN_PATTERNS_PIZZA_H

#include <iostream>
#include <list>
#include <string>

class Pizza {
public:
    void prepare() {
        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for (auto &it : toppings) { std::cout << "  " << it << std::endl; }
    }

    void bake() { std::cout << "Bake for 25 minutes at 350" << std::endl; }

    virtual void cut() { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }

    void box() { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

    const std::string &getName() const { return name; }

protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::list<std::string> toppings;
};

#endif

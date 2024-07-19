#ifndef DESIGN_PATTERN_MENU_ITEM_H
#define DESIGN_PATTERN_MENU_ITEM_H

#include <iostream>
#include <string>

#include "menu_component.h"

class MenuItem : public MenuComponent {
public:
    MenuItem(const std::string &name, const std::string &description, bool vegetarian, double price)
        : name(name), description(description), vegetarian(vegetarian), price(price) {}

    const std::string &getName() const override { return name; }

    const std::string &getDescription() const override { return description; }

    double getPrice() const override { return price; }

    bool isVegetarian() const override { return vegetarian; }

    void print() const override {
        std::cout << "  " << getName();
        if (isVegetarian()) { std::cout << "(v)"; }
        std::cout << ", " << getPrice() << std::endl;
        std::cout << "     -- " << getDescription() << std::endl;
    }

private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};

#endif

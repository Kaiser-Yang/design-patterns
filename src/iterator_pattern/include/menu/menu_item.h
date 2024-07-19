#ifndef DESIGN_PATTERN_MENU_ITEM_H
#define DESIGN_PATTERN_MENU_ITEM_H

#include <string>

class MenuItem {
public:
    MenuItem(const std::string &name,
             const std::string &description,
             bool vegetarian,
             double price) {
        this->name        = name;
        this->description = description;
        this->vegetarian  = vegetarian;
        this->price       = price;
    }
    const std::string &getName() const { return name; }
    const std::string &getDescription() const { return description; }
    double getPrice() const { return price; }
    bool isVegetarian() const { return vegetarian; }

private:
    std::string name;
    std::string description;
    bool vegetarian;
    double price;
};

#endif

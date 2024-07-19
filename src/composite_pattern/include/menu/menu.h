#ifndef DESIGN_PATTERN_MENU_H
#define DESIGN_PATTERN_MENU_H

#include <iostream>
#include <string>
#include <vector>

#include "menu_component.h"

class Menu : public MenuComponent {
public:
    Menu(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}

    void add(const std::shared_ptr<MenuComponent> &menuComponent) override {
        menuComponentVec.push_back(menuComponent);
    }

    void remove(const std::shared_ptr<MenuComponent> &menuComponent) override {
        for (auto it = menuComponentVec.begin(); it != menuComponentVec.end(); ++it) {
            if (*it == menuComponent) {
                menuComponentVec.erase(it);
                return;
            }
        }
    }

    std::shared_ptr<MenuComponent> getChild(size_t i) const override { return menuComponentVec[i]; }

    const std::string &getName() const override { return name; }

    const std::string &getDescription() const override { return description; }

    void print() const override {
        std::cout << "\n" << getName();
        std::cout << ", " << getDescription() << "\n";
        std::cout << "---------------------\n";
        for (const auto &menu_component : menuComponentVec) { menu_component->print(); }
    }

private:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<MenuComponent>> menuComponentVec;
};

#endif

#ifndef DESIGN_PATTERN_WAITRESS_H
#define DESIGN_PATTERN_WAITRESS_H

#include <iostream>
#include <memory>
#include <vector>

#include "menu/menu_component.h"

class Waitress {
public:
    void addMenu(const std::shared_ptr<MenuComponent> &menu) { menuVec.push_back(menu); }

    void printMenu() const {
        for (auto menu : menuVec) { menu->print(); }
    }

private:
    std::vector<std::shared_ptr<MenuComponent>> menuVec;
};

#endif

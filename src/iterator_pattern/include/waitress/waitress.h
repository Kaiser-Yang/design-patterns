#ifndef DESIGN_PATTERN_WAITRESS_H
#define DESIGN_PATTERN_WAITRESS_H

#include <iostream>
#include <memory>
#include <vector>

#include "iterator/iterator.h"
#include "menu/menu.h"
#include "menu/menu_item.h"

class Waitress {
public:
    void addMenu(const std::shared_ptr<Menu> &menu) { menus.push_back(menu); }
    void printMenu() {
        for (const auto &menu : menus) {
            auto iter = menu->createIterator();
            while (iter->hasNext()) {
                MenuItem &item = iter->next();
                std::cout << item.getName() << ", " << item.getPrice() << " -- "
                          << item.getDescription() << std::endl;
            }
        }
    }

private:
    std::vector<std::shared_ptr<Menu>> menus;
};

#endif

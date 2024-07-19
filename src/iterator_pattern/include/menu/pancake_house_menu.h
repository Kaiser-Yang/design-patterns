#ifndef DESIGN_PATTERN_PANCAKE_HOUSE_MENU_H
#define DESIGN_PATTERN_PANCAKE_HOUSE_MENU_H

#include <list>

#include "iterator/pancake_house_menu_iterator.h"
#include "menu/menu.h"
#include "menu/menu_item.h"

class PancakeHouseMenu : public Menu {
public:
    void addItem(const MenuItem &item) { itemList.push_back(item); }
    std::shared_ptr<Iterator<MenuItem>> createIterator() override {
        return std::make_shared<PancakeHouseMenuIterator>(itemList);
    }

private:
    std::list<MenuItem> itemList;
};

#endif

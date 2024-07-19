#ifndef DESIGN_PATTERN_DINER_MENU_H
#define DESIGN_PATTERN_DINER_MENU_H

#include <memory>
#include <vector>

#include "iterator/diner_menu_iterator.h"
#include "menu.h"
#include "menu_item.h"

class DinerMenu : public Menu {
public:
    std::shared_ptr<Iterator<MenuItem>> createIterator() override {
        return std::make_shared<DinerMenuIterator>(itemVec);
    }
    void addItem(const MenuItem &item) { itemVec.push_back(item); }

private:
    std::vector<MenuItem> itemVec;
};

#endif

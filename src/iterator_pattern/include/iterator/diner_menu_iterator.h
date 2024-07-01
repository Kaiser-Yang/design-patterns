#ifndef DESIGN_PATTERN_DINER_MENU_ITERATOR_H
#define DESIGN_PATTERN_DINER_MENU_ITERATOR_H

#include <vector>

#include "iterator.h"
#include "menu/menu.h"
#include "menu/menu_item.h"

class DinerMenuIterator : public Iterator<MenuItem> {
public:
    DinerMenuIterator(std::vector<MenuItem> &item) : item(item), position(0){};
    bool hasNext() override { return position < item.size(); }
    MenuItem &next() override { return item[position++]; }
    Iterator<MenuItem> &remove() override {
        item.erase(item.begin() + position);
        return *this;
    }

private:
    std::vector<MenuItem> &item;
    size_t position;
};

#endif

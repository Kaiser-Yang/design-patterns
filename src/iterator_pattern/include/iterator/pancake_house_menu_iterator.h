#ifndef DESIGN_PATTERN_PANCAKE_HOUSE_MENU_ITERATOR_H
#define DESIGN_PATTERN_PANCAKE_HOUSE_MENU_ITERATOR_H

#include <list>

#include "iterator/iterator.h"
#include "menu/menu_item.h"

class PancakeHouseMenuIterator : public Iterator<MenuItem> {
public:
    PancakeHouseMenuIterator(std::list<MenuItem> &item) : item(item), position(item.begin()){};
    bool hasNext() override { return position != item.end(); }
    MenuItem &next() override { return *position++; }
    Iterator<MenuItem> &remove() override {
        position = item.erase(position);
        return *this;
    }

private:
    std::list<MenuItem> &item;
    std::list<MenuItem>::iterator position;
};

#endif

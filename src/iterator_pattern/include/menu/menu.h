#ifndef DESIGN_PATTERN_MENU_H
#define DESIGN_PATTERN_MENU_H

#include <memory>

#include "iterator/iterator.h"
#include "menu/menu_item.h"

class Menu {
public:
    virtual std::shared_ptr<Iterator<MenuItem>> createIterator() = 0;
};

#endif

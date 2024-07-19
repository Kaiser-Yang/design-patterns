#include <memory>

#include "iterator/diner_menu_iterator.h"
#include "iterator/iterator.h"
#include "iterator/pancake_house_menu_iterator.h"
#include "menu/diner_menu.h"
#include "menu/menu_item.h"
#include "menu/pancake_house_menu.h"
#include "waitress/waitress.h"

void IteratorPatternTest() {
    std::shared_ptr<PancakeHouseMenu> pancakeHouseMenu = std::make_shared<PancakeHouseMenu>();
    std::shared_ptr<DinerMenu> dinerMenu               = std::make_shared<DinerMenu>();

    pancakeHouseMenu->addItem(
        MenuItem("K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99));
    pancakeHouseMenu->addItem(
        MenuItem("Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99));
    pancakeHouseMenu->addItem(
        MenuItem("Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49));
    pancakeHouseMenu->addItem(MenuItem(
        "Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59));

    dinerMenu->addItem(MenuItem(
        "Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99));
    dinerMenu->addItem(MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99));
    dinerMenu->addItem(
        MenuItem("Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29));
    dinerMenu->addItem(MenuItem(
        "Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05));

    Waitress waitress;
    waitress.addMenu(pancakeHouseMenu);
    waitress.addMenu(dinerMenu);
    waitress.printMenu();
}

int main() {
    IteratorPatternTest();
    return 0;
}

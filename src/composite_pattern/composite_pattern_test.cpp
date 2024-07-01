#include "menu/menu.h"
#include "menu/menu_component.h"
#include "menu/menu_item.h"
#include "waitress/waitress.h"

void CompositePatternTest() {
    std::shared_ptr<MenuComponent> pancakeHouseMenu =
        std::make_shared<Menu>("PANCAKE HOUSE MENU", "Breakfast");
    std::shared_ptr<MenuComponent> dinerMenu = std::make_shared<Menu>("DINER MENU", "Lunch");
    std::shared_ptr<MenuComponent> cafeMenu  = std::make_shared<Menu>("CAFE MENU", "Dinner");
    std::shared_ptr<MenuComponent> dessertMenu =
        std::make_shared<Menu>("DESSERT MENU", "Dessert of course!");

    std::shared_ptr<MenuComponent> allMenus =
        std::make_shared<Menu>("ALL MENUS", "All menus combined");

    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);
    allMenus->add(dessertMenu);

    pancakeHouseMenu->add(std::make_shared<MenuItem>(
        "K&B's Pancake Breakfast", "Pancakes with scrambled eggs, and toast", true, 2.99));
    pancakeHouseMenu->add(std::make_shared<MenuItem>(
        "Regular Pancake Breakfast", "Pancakes with fried eggs, sausage", false, 2.99));
    pancakeHouseMenu->add(std::make_shared<MenuItem>(
        "Blueberry Pancakes", "Pancakes made with fresh blueberries", true, 3.49));
    pancakeHouseMenu->add(std::make_shared<MenuItem>(
        "Waffles", "Waffles, with your choice of blueberries or strawberries", true, 3.59));

    dinerMenu->add(std::make_shared<MenuItem>(
        "Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99));
    dinerMenu->add(std::make_shared<MenuItem>(
        "BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99));
    dinerMenu->add(std::make_shared<MenuItem>(
        "Soup of the day", "Soup of the day, with a side of potato salad", false, 3.29));
    dinerMenu->add(std::make_shared<MenuItem>(
        "Hotdog", "A hot dog, with saurkraut, relish, onions, topped with cheese", false, 3.05));
    dinerMenu->add(std::make_shared<MenuItem>(
        "Steamed Veggies and Brown Rice", "Steamed vegetables over brown rice", true, 3.99));

    cafeMenu->add(
        std::make_shared<MenuItem>("Veggie Burger and Air Fries",
                                   "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
                                   true,
                                   3.99));
    cafeMenu->add(std::make_shared<MenuItem>(
        "Soup of the day", "A cup of the soup of the day, with a side salad", false, 3.69));
    cafeMenu->add(std::make_shared<MenuItem>(
        "Burrito", "A large burrito, with whole pinto beans, salsa, guacamole", true, 4.29));

    dessertMenu->add(std::make_shared<MenuItem>(
        "Apple Pie", "Apple pie with a flakey crust, topped with vanilla ice cream", true, 1.59));
    dessertMenu->add(std::make_shared<MenuItem>(
        "Cheesecake", "Creamy New York cheesecake, with a chocolate graham crust", true, 1.99));
    dessertMenu->add(std::make_shared<MenuItem>(
        "Sorbet", "A scoop of raspberry and a scoop of lime", true, 1.89));

    Waitress waitress;
    waitress.addMenu(std::dynamic_pointer_cast<Menu>(allMenus));
    waitress.printMenu();
}

int main() {
    CompositePatternTest();
    return 0;
}

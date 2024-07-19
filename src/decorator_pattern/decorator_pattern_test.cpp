#include <iostream>
#include <memory>

#include "beverage/beverage.h"
#include "beverage/dark_roast.h"
#include "beverage/decorator/milk.h"
#include "beverage/decorator/mocha.h"
#include "beverage/decorator/soy.h"
#include "beverage/decorator/whip.h"
#include "beverage/espresso.h"
#include "beverage/house_blend.h"

void DecoratorPatternTest() {
    std::unique_ptr<Beverage> beverage1, beverage2, beverage3;

    beverage1 = std::make_unique<Espresso>();
    std::cout << beverage1->getDescription() << " $" << beverage1->cost() << std::endl;

    beverage2 = std::make_unique<DarkRoast>();
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));
    beverage2 = std::make_unique<Mocha>(std::move(beverage2));
    beverage2 = std::make_unique<Whip>(std::move(beverage2));
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

    beverage3 = std::make_unique<HouseBlend>();
    beverage3 = std::make_unique<Soy>(std::move(beverage3));
    beverage3 = std::make_unique<Mocha>(std::move(beverage3));
    beverage3 = std::make_unique<Whip>(std::move(beverage3));
    beverage3 = std::make_unique<Milk>(std::move(beverage3));
    std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;
}

int main() {
    DecoratorPatternTest();
    return 0;
}

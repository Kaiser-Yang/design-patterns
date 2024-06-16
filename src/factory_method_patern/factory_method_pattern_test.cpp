#include <iostream>
#include <memory>

#include "pizza_store/new_york_style_prizza_store.h"
#include "pizza_store/pizza_store.h"

// use different pizza store classes to test
void FactoryMethodPatternTest() {
    // create new york style pizza store
    std::unique_ptr<PizzaStore> nyStore = std::make_unique<NewYorkStylePizzaStore>();
    Pizza pizza                         = nyStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza.getName() << std::endl;

    pizza = nyStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza.getName() << std::endl;

    // create chicago style pizza store
    std::unique_ptr<PizzaStore> chicagoStore = std::make_unique<NewYorkStylePizzaStore>();
    pizza                                    = chicagoStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza.getName() << std::endl;

    pizza = chicagoStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza.getName() << std::endl;
}

int main() {
    FactoryMethodPatternTest();
    return 0;
}

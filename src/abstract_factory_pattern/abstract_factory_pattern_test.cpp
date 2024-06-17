#include <memory>

#include "pizza_store/chicago_style_pizza_store.h"
#include "pizza_store/new_york_style_pizza_store.h"
#include "pizza_store/pizza_store.h"

void AbstractFactoryPatternTest() {
    std::unique_ptr<PizzaStore> newYorkStylePizzaStore = std::make_unique<NewYorkStylePizzaStore>();
    std::unique_ptr<PizzaStore> chicagoStylePizzaStore = std::make_unique<ChicagoStylePizzaStore>();

    std::unique_ptr<Pizza> pizza;
    pizza = newYorkStylePizzaStore->orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    pizza = chicagoStylePizzaStore->orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;

    pizza = newYorkStylePizzaStore->orderPizza("clam");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    pizza = chicagoStylePizzaStore->orderPizza("clam");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;

    pizza = newYorkStylePizzaStore->orderPizza("pepperoni");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    pizza = chicagoStylePizzaStore->orderPizza("pepperoni");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;

    pizza = newYorkStylePizzaStore->orderPizza("veggie");
    std::cout << "Ethan ordered a " << pizza->getName() << std::endl;
    pizza = chicagoStylePizzaStore->orderPizza("veggie");
    std::cout << "Joel ordered a " << pizza->getName() << std::endl;
}

int main() {
    AbstractFactoryPatternTest();
    return 0;
}


#include <iostream>

#include "pizza_store/pizza_store.h"

void SimpleFactoryTest() {
    PizzaStore store;

    store.orderPizza("cheese");
    store.orderPizza("pepperoni");
    store.orderPizza("clam");
    store.orderPizza("veggie");
}

int main() {
    SimpleFactoryTest();
    return 0;
}

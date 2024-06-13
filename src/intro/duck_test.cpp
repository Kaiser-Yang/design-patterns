#include <iostream>
#include <string>

#include "duck/decoy_duck.h"
#include "duck/mallard_duck.h"
#include "duck/redhead_duck.h"
#include "duck/rubber_duck.h"

void testDuck(Duck &&duck, const std::string &name) {
    std::cout << "Start testing " << name << ":\n";
    duck.display();
    duck.performFly();
    duck.performQuack();
    duck.swim();
    std::cout << "Finish testing " << name << ".\n\n";
}

int main() {
    testDuck(DecoyDuck(), "DecoyDuck");
    testDuck(MallardDuck(), "MallardDuck");
    testDuck(RedheadDuck(), "RedheadDuck");
    testDuck(RubberDuck(), "RubberDuck");
    return 0;
}

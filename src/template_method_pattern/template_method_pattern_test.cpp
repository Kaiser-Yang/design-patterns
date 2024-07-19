#include <iostream>

#include "caffee.h"
#include "caffeine_beverage.h"
#include "tea.h"

void TemplateMethodPatternTest() {
    Caffee caffee;
    Tea tea;
    std::cout << "Making caffee..." << std::endl;
    caffee.prepareRecipe();
    std::cout << "Making tea..." << std::endl;
    tea.prepareRecipe();
}

int main() {
    TemplateMethodPatternTest();
    return 0;
}

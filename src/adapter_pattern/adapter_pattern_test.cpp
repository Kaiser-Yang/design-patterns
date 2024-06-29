#include <iostream>
#include <memory>

#include "adapter/turkey_adpater.h"
#include "duck/duck.h"
#include "turkey/wild_trukey.h"

void AdapterPatternTest() {
    std::shared_ptr<Turkey> turkey      = std::make_shared<WildTurkey>();
    std::shared_ptr<Duck> turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);

    std::cout << "The Turkey says..." << std::endl;
    turkey->gobble();
    turkey->fly();

    std::cout << "The TurkeyAdapter says..." << std::endl;
    turkeyAdapter->quack();
    turkeyAdapter->fly();
}

int main() {
    AdapterPatternTest();
    return 0;
}

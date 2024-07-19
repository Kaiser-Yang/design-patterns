#include <memory>

#include "composite/flock.h"
#include "counter/quack_counter.h"
#include "factory/abstract_factory.h"
#include "factory/counting_duck_factory.h"
#include "factory/factory_method.h"
#include "observer/quackologist.h"
#include "quackable.h"

size_t QuackCounter::quacks = 0;

void simulate(std::shared_ptr<Quackable> duck) { duck->quack(); }

void MultiPatternTest() {
    std::unique_ptr<AbstractFactory> factory = std::make_unique<CountingDuckFactory>();

    std::shared_ptr<Flock> flockOfDucks    = FactoryMethod::createFlock();
    std::shared_ptr<Quackable> redheadDuck = factory->createRedheadDuck();
    std::shared_ptr<Quackable> duckCall    = factory->createDuckCall();
    std::shared_ptr<Quackable> rubberDuck  = factory->createRubberDuck();
    std::shared_ptr<Quackable> goose       = factory->createGooseAdapter();
    flockOfDucks->add(redheadDuck);
    flockOfDucks->add(duckCall);
    flockOfDucks->add(rubberDuck);
    flockOfDucks->add(goose);

    std::shared_ptr<Flock> flockOfMallards = FactoryMethod::createFlock();
    std::shared_ptr<Quackable> mallard1    = factory->createMallardDuck();
    std::shared_ptr<Quackable> mallard2    = factory->createMallardDuck();
    std::shared_ptr<Quackable> mallard3    = factory->createMallardDuck();
    std::shared_ptr<Quackable> mallard4    = factory->createMallardDuck();
    flockOfMallards->add(mallard1);
    flockOfMallards->add(mallard2);
    flockOfMallards->add(mallard3);
    flockOfMallards->add(mallard4);

    std::shared_ptr<Quackologist> quackologist = std::make_shared<Quackologist>();
    flockOfDucks->registerObserver(quackologist);

    simulate(flockOfDucks);
    simulate(flockOfMallards);

    std::cout << "The ducks quacked " << QuackCounter::getQuacks() << " times" << std::endl;
}

int main() {
    MultiPatternTest();
    return 0;
}

#ifndef DESIGN_PATTERNS_DUCK_H
#define DESIGN_PATTERNS_DUCK_H

#include <iostream>
#include <memory>

#include "fly_behavior/fly_behavior.h"
#include "quack_behavior/quack_behavior.h"

class Duck {
public:
    void performQuack() { quackBehavior->quack(); }

    void performFly() { flyBehavior->fly(); }

    void swim() { std::cout << "I'm swimming.\n"; }

    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb) { flyBehavior = std::move(fb); }

    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb) { quackBehavior = std::move(qb); }

    virtual void display() { std::cout << "I'm a duck.\n"; }

    virtual ~Duck() = default;

private:
    std::unique_ptr<FlyBehavior> flyBehavior;
    std::unique_ptr<QuackBehavior> quackBehavior;
};

#endif

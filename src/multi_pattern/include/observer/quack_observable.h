#ifndef DESIGN_PATTERNS_QUACK_OBSERVABLE_H
#define DESIGN_PATTERNS_QUACK_OBSERVABLE_H

#include <memory>
#include <string>

class Observer;

class QuackObservable {
public:
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
    const std::string & getName() { return name; }
protected:
    std::string name;
};

#endif


#ifndef DESIGN_PATTERNS_SUBJECT_H
#define DESIGN_PATTERNS_SUBJECT_H

#include <algorithm>
#include <memory>
#include <vector>

#include "observer/observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void registerObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    virtual void removeObserver(std::shared_ptr<Observer> observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) { observers.erase(it); }
    }

    virtual void notifyObservers() = 0;

protected:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif

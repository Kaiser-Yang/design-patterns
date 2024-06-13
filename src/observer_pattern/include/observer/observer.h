#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

class Observer {
public:
    // push type
    virtual void update(double temprature, double humidity, double pressure) = 0;

    // pull type
    virtual void update() = 0;

    virtual ~Observer() = default;
};

#endif

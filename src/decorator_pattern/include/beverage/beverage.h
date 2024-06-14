#ifndef DESIGN_PATTERNS_BEVERAGE_H
#define DESIGN_PATTERNS_BEVERAGE_H

#include <string>

class Beverage {
public:
    virtual double cost() const = 0;
    virtual const std::string &getDescription() const { return description; }
    virtual ~Beverage() = default;

protected:
    std::string description;
};

#endif

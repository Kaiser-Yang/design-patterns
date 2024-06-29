#ifndef DESIGN_PATTERNS_DUCK_H
#define DESIGN_PATTERNS_DUCK_H

class Duck {
public:
    virtual void quack() = 0;
    virtual void fly()   = 0;
};

#endif

#ifndef DESIGN_PATTERNS_TURKEY_ADAPTER_H
#define DESIGN_PATTERNS_TURKEY_ADAPTER_H

#include <memory>
#include "duck/duck.h"
#include "turkey/turkey.h"

class TurkeyAdapter : public Duck {
public:
    TurkeyAdapter(std::shared_ptr<Turkey> turkey) : turkey(turkey) {}
    void quack() override {
        turkey->gobble();
    }
    void fly() override {
        for (int i = 0; i < 5; i++) {
            turkey->fly();
        }
    }
private:
    std::shared_ptr<Turkey> turkey;
};

#endif

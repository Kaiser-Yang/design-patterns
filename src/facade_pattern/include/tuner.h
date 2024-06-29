#ifndef DESIGN_PATTERN_TUNER_H
#define DESIGN_PATTERN_TUNER_H

#include <memory>

class Amplifier;

class Tuner {
public:
    void on();
    void off();
    void setFrequency(double frequency);
    void setAm();
    void setFm();

private:
    std::shared_ptr<Amplifier> amplifier;
};

#endif

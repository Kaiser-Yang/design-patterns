#ifndef DESIGN_PATTERN_MODEL_BEAT_MODEL_INTERFACE_H
#define DESIGN_PATTERN_MODEL_BEAT_MODEL_INTERFACE_H

#include <memory>
#include "observer/beat_observer.h"
#include "observer/bpm_observer.h"

class BeatModelInterface {
public:
    virtual void initialize() = 0;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void setBPM(int bpm) = 0;
    virtual size_t getBPM() = 0;
    virtual void registerObserver(std::shared_ptr<BeatObserver>) = 0;
    virtual void removeObserver(std::shared_ptr<BeatObserver>) = 0;
    virtual void registerObserver(std::shared_ptr<BPMObserver>) = 0;
    virtual void removeObserver(std::shared_ptr<BPMObserver>) = 0;
    virtual void notifyBeatObservers() = 0;
    virtual void notifyBPMObservers() = 0;
};

#endif

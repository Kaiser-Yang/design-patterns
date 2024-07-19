#ifndef DESIGN_PATTERN_CONTROLLER_CONTROLLER_INTERFACE_H
#define DESIGN_PATTERN_CONTROLLER_CONTROLLER_INTERFACE_H

class ControllerInterface {
public:
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void increaseBPM() = 0;
    virtual void decreaseBPM() = 0;
    virtual void setBPM(int bpm) = 0;
};

#endif

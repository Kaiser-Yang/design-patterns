#ifndef DESIGN_PATTERNS_LIGHT_OFF_COMMAND_H
#define DESIGN_PATTERNS_LIGHT_OFF_COMMAND_H

#include <memory>

#include "command.h"
#include "device/light.h"

class LightOffCommand : public Command {
public:
    explicit LightOffCommand(std::shared_ptr<Light> light) : light(light) {}
    void execute() override { light->off(); }
    void undo() override { light->on(); }

private:
    std::shared_ptr<Light> light;
};

#endif

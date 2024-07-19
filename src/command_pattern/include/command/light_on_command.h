#ifndef DESIGN_PATTERNS_LIGHT_ON_COMMAND_H
#define DESIGN_PATTERNS_LIGHT_ON_COMMAND_H

#include <memory>

#include "command.h"
#include "device/light.h"

class LightOnCommand : public Command {
public:
    explicit LightOnCommand(std::shared_ptr<Light> light) : light(light) {}
    void execute() override { light->on(); }
    void undo() override { light->off(); }

private:
    std::shared_ptr<Light> light;
};

#endif

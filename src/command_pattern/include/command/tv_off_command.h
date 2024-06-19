#ifndef DESIGN_PATTERNS_TV_OFF_COMMAND_H
#define DESIGN_PATTERNS_TV_OFF_COMMAND_H

#include <memory>

#include "command.h"
#include "device/tv.h"

class TVOffCommand : public Command {
public:
    explicit TVOffCommand(std::shared_ptr<TV> tv) : tv(tv) {}
    void execute() override { tv->off(); }
    void undo() override { tv->on(); }

private:
    std::shared_ptr<TV> tv;
};

#endif

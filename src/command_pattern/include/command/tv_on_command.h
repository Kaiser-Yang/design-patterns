#ifndef DESIGN_PATTERNS_TV_ON_COMMAND_H
#define DESIGN_PATTERNS_TV_ON_COMMAND_H

#include <memory>

#include "command.h"
#include "device/tv.h"

class TVOnCommand : public Command {
public:
    explicit TVOnCommand(std::shared_ptr<TV> tv) : tv(tv) {}
    void execute() override { tv->on(); }
    void undo() override { tv->off(); }

private:
    std::shared_ptr<TV> tv;
};

#endif

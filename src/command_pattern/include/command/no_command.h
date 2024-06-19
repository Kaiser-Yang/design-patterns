#ifndef DESIGN_PATTERNS_NO_COMMAND_H
#define DESIGN_PATTERNS_NO_COMMAND_H

#include <iostream>

#include "command.h"

class NoCommand : public Command {
public:
    void execute() override {
        std::cout << "No command" << std::endl;
    }
    void undo() override {
        std::cout << "No command" << std::endl;
    }
};

#endif

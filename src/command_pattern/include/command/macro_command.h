#ifndef DESIGN_PATTERNS_MACRO_COMMAND_H
#define DESIGN_PATTERNS_MACRO_COMMAND_H

#include <memory>
#include <vector>

#include "command.h"

class MacroCommand : public Command {
public:
    explicit MacroCommand(const std::vector<std::shared_ptr<Command>> &commands)
        : commands(commands) {}

    explicit MacroCommand(std::vector<std::shared_ptr<Command>> &&commands)
        : commands(std::move(commands)) {}

    void execute() override {
        for (const auto &command : commands) { command->execute(); }
    }

    void undo() override {
        for (auto rit = commands.rbegin(); rit != commands.rend(); ++rit) { (*rit)->undo(); }
    }

private:
    std::vector<std::shared_ptr<Command>> commands;
};

#endif

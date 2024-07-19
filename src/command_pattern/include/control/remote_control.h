#ifndef DESIGN_PATTERNS_REMOTE_CONTROL_H

#include <memory>
#include <vector>

#include "command/command.h"
#include "command/no_command.h"

class RemoteControl {
public:
    enum class BUTTON_NAME : short { TV, LIGHT, PARTY_MODE, NUM_DEVICES };

    RemoteControl() {
        onCommand.resize(static_cast<size_t>(BUTTON_NAME::NUM_DEVICES),
                         std::make_shared<NoCommand>());
        offCommand.resize(static_cast<size_t>(BUTTON_NAME::NUM_DEVICES),
                          std::make_shared<NoCommand>());
        undoCommand = std::make_shared<NoCommand>();
    }

    void pressOnButton(const BUTTON_NAME &deviceName) {
        onCommand[static_cast<size_t>(deviceName)]->execute();
        undoCommand = onCommand[static_cast<size_t>(deviceName)];
    }

    void pressOffButton(const BUTTON_NAME &deviceName) {
        offCommand[static_cast<size_t>(deviceName)]->execute();
        undoCommand = offCommand[static_cast<size_t>(deviceName)];
    }

    void setCommand(const BUTTON_NAME &deviceName,
                    std::shared_ptr<Command> onCommand,
                    std::shared_ptr<Command> offCommand) {
        this->onCommand[static_cast<size_t>(deviceName)]  = onCommand;
        this->offCommand[static_cast<size_t>(deviceName)] = offCommand;
    }

    void pressUndoButton() { undoCommand->undo(); }

private:
    std::vector<std::shared_ptr<Command>> onCommand;
    std::vector<std::shared_ptr<Command>> offCommand;
    std::shared_ptr<Command> undoCommand;
};

#endif

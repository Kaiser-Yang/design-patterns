#include <memory>

#include "command/light_off_command.h"
#include "command/light_on_command.h"
#include "command/macro_command.h"
#include "command/no_command.h"
#include "command/tv_off_command.h"
#include "command/tv_on_command.h"
#include "control/remote_control.h"
#include "device/light.h"
#include "device/tv.h"

void CommandPatternTest() {
    std::shared_ptr<Light> light = std::make_shared<Light>();
    std::shared_ptr<TV> tv       = std::make_shared<TV>();

    RemoteControl remoteControl;

    remoteControl.setCommand(RemoteControl::BUTTON_NAME::LIGHT,
                             std::make_shared<LightOnCommand>(light),
                             std::make_shared<LightOffCommand>(light));
    remoteControl.setCommand(RemoteControl::BUTTON_NAME::TV,
                             std::make_shared<TVOnCommand>(tv),
                             std::make_shared<TVOffCommand>(tv));
    remoteControl.setCommand(
        RemoteControl::BUTTON_NAME::PARTY_MODE,
        std::make_shared<MacroCommand>(std::vector<std::shared_ptr<Command>>{
            std::make_shared<LightOnCommand>(light), std::make_shared<TVOnCommand>(tv)}),
        std::make_shared<MacroCommand>(std::vector<std::shared_ptr<Command>>{
            std::make_shared<LightOffCommand>(light), std::make_shared<TVOffCommand>(tv)}));

    remoteControl.pressOnButton(RemoteControl::BUTTON_NAME::LIGHT);
    remoteControl.pressOffButton(RemoteControl::BUTTON_NAME::LIGHT);
    remoteControl.pressUndoButton();
    remoteControl.pressOnButton(RemoteControl::BUTTON_NAME::TV);
    remoteControl.pressOffButton(RemoteControl::BUTTON_NAME::TV);
    remoteControl.pressUndoButton();
    remoteControl.pressOnButton(RemoteControl::BUTTON_NAME::PARTY_MODE);
    remoteControl.pressOffButton(RemoteControl::BUTTON_NAME::PARTY_MODE);
    remoteControl.pressUndoButton();
}

int main() {
    CommandPatternTest();
    return 0;
}

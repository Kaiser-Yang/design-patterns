#include <memory>

#include "model/beat_model.h"
#include "controller/controller_interface.h"
#include "controller/beat_controller.h"

void CompoundDesignTest() {
    std::shared_ptr<BeatModelInterface> model = std::make_shared<BeatModel>();
    std::shared_ptr<ControllerInterface> controller = std::make_shared<BeatController>(model);
    controller->init();
}

int main() {
    CompoundDesignTest();
    return 0;
}

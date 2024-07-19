#ifndef DESIGN_PATTERN_BEAT_CONTROLLER_H
#define DESIGN_PATTERN_BEAT_CONTROLLER_H

#include "controller_interface.h"
#include "model/beat_model_interface.h"
#include "view/dj_view.h"

class BeatController : public ControllerInterface,
                       public std::enable_shared_from_this<BeatController> {
public:
    BeatController(std::shared_ptr<BeatModelInterface> model) : model(model) {}

    void init() override {
        model->initialize();
        view = std::make_shared<DJView>(model, shared_from_this());
        view->init();
        view->handleEvent();
    }

    void start() override {
        model->on();
        view->disableStartMenuItem();
        view->enableStopMenuItem();
    }

    void stop() override {
        model->off();
        view->disableStopMenuItem();
        view->enableStartMenuItem();
    }

    void increaseBPM() override {
        int bpm = model->getBPM();
        model->setBPM(bpm + 1);
    }

    void decreaseBPM() override {
        int bpm = model->getBPM();
        model->setBPM(bpm - 1);
    }

    void setBPM(int bpm) override { model->setBPM(bpm); }

private:
    std::shared_ptr<BeatModelInterface> model;
    std::shared_ptr<DJView> view;
};

#endif

#ifndef DESIGN_PATTERN_VIEW_DJ_VIEW_H
#define DESIGN_PATTERN_VIEW_DJ_VIEW_H

#include <iostream>
#include <memory>

#include "controller/controller_interface.h"
#include "model/beat_model_interface.h"
#include "observer/beat_observer.h"
#include "observer/bpm_observer.h"

// we'll use CLI to simulate the view
class DJView : public BeatObserver, public BPMObserver, public std::enable_shared_from_this<DJView> {
public:
    DJView(std::shared_ptr<BeatModelInterface> model,
           std::shared_ptr<ControllerInterface> controller)
        : model(model), controller(controller) {}

    void init() {
        model->registerObserver(std::dynamic_pointer_cast<BeatObserver>(shared_from_this()));
        model->registerObserver(std::dynamic_pointer_cast<BPMObserver>(shared_from_this()));
        disableStopMenuItem();
        enableStartMenuItem();
    }

    void enableStartMenuItem() { canStop = false; }

    void disableStartMenuItem() { canStop = true; }

    void enableStopMenuItem() { canStop = true; }

    void disableStopMenuItem() { canStop = false; }

    void updateBeat() override { std::cout << "Observer Beat!" << std::endl; }

    void updateBPM() override { std::cout << "Observer BPM: " << model->getBPM() << std::endl; }

    void handleEvent() {
        std::string op;
        size_t bpm = 0;
        while (true) {
            std::cin >> op;
            if (op == "+") {
                controller->increaseBPM();
            } else if (op == "-") {
                controller->decreaseBPM();
            } else if (op == "set") {
                std::cin >> bpm;
                controller->setBPM(bpm);
            } else if (op == "stop") {
                if (!canStop) { continue; }
                controller->stop();
            } else if (op == "start") {
                if (canStop) { continue; }
                controller->start();
            } else if (op == "quit") {
                std::cout << "Bye!\n";
                break;
            } else if (op == "?" || op == "help") {
                printHelpInfo();
            } else {
                std::cout << "Invalid operation" << std::endl;
            }
            std::cout << "BPM: " << model->getBPM() << "\n";
        }
    }

private:
    void printHelpInfo() {
        std::cout << "+\n";
        std::cout << "-\n";
        std::cout << "set <bpm>\n";
        std::cout << "stop\n";
        std::cout << "start\n";
        std::cout << "quit\n";
        std::cout << "? | help\n";
    }
    std::shared_ptr<BeatModelInterface> model;
    std::shared_ptr<ControllerInterface> controller;
    bool canStop = false;
};

#endif

#ifndef DESIGN_PATTERN_MODEL_BEAT_MODEL_H
#define DESIGN_PATTERN_MODEL_BEAT_MODEL_H

#include <atomic>
#include <future>
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

#include "model/beat_model_interface.h"

class BeatModel : public BeatModelInterface {
public:
    void initialize() override {
        // do some initialization here
        std::cout << "Beat Model initialized" << std::endl;
    }

    void on() override {
        setBPM(90);
        stop = false;
        run();
    }

    void off() override {
        stopBeat();
        stop = true;
        f.get();
    }

    void setBPM(int bpm) override {
        this->bpm.store(bpm, std::memory_order_relaxed);
        notifyBPMObservers();
    }

    size_t getBPM() override {
        return this->bpm.load(std::memory_order_relaxed);
    }

    void registerObserver(std::shared_ptr<BeatObserver> bo) override {
        beatObserver.push_back(bo);
    }

    void removeObserver(std::shared_ptr<BeatObserver> bo) override {
        beatObserver.erase(std::remove(beatObserver.begin(), beatObserver.end(), bo), beatObserver.end());
    }

    void registerObserver(std::shared_ptr<BPMObserver> bo) override {
        bpmObserver.push_back(bo);
    }

    void removeObserver(std::shared_ptr<BPMObserver> bo) override {
        bpmObserver.push_back(bo);
    }

    void run() {
        f = std::async(std::launch::async, [this] () {
            while (!stop) {
                playBeat();
                std::this_thread::sleep_for(std::chrono::milliseconds(60000 / bpm));
            }
        });
    }

    ~BeatModel() {
        stop = true;
        f.get();
    }

    void notifyBeatObservers() override {
        for (auto& bo : beatObserver) {
            bo->updateBeat();
        }
    }

    void notifyBPMObservers() override {
        for (auto& bo : bpmObserver) {
            bo->updateBPM();
        }
    }

private:
    void playBeat() {
        std::cout << "Playing the beat\n";
        notifyBeatObservers();
    }

    void stopBeat() {
        std::cout << "Beat stopped\n";
        notifyBeatObservers();
    }

    std::future<void> f;
    std::atomic_size_t bpm = 90;
    bool stop = false;
    std::vector<std::shared_ptr<BeatObserver>> beatObserver;
    std::vector<std::shared_ptr<BPMObserver>> bpmObserver;
};

#endif

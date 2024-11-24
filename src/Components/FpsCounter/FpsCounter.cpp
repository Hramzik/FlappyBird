
//--------------------------------------------------

#include <iostream>

#include "FpsCounter.h"

//--------------------------------------------------

FpsCounter::FpsCounter ():
        start_time_ (std::chrono::high_resolution_clock::now()) {}

void FpsCounter::draw () {

    ++frame_count_;
    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = current_time - start_time_;

    if (elapsed.count () >= 1) {

        std::cout << "FPS: " << frame_count_ << std::endl;
        frame_count_ = 0;
        start_time_ = current_time;
    }
}

//--------------------------------------------------


//--------------------------------------------------

#pragma once

#include <chrono>
#include "src/Components/Component/Component.h"

//--------------------------------------------------

// обнуляется каждую секунду
class FpsCounter: public Component {

  public:
    FpsCounter ();
    void draw () override;

  private:
    int frame_count_ = 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
};

//--------------------------------------------------

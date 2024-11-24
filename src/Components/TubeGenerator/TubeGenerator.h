
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/GameObject/GameObject.h"
#include "src/GameFactory/GameFactory.h"

//--------------------------------------------------

// generates tubes around anker
class TubeGenerator: public Component {

  public:
    TubeGenerator (GameObject& anker, std::vector<GameObject*>& tubes, GameFactory& factory);
    void act (double dt) override;

  private:
    GameObject&               anker_;
    std::vector<GameObject*>& tubes_;
    GameFactory& factory_;

  private:
    static constexpr double GENERATION_RADIUS = 800; // guaranteed to be filled
    static constexpr double GENERATION_STEP   = 350;
    static constexpr double VERTICAL_GAP      = 210;
    static constexpr double MIN_TUBE_HEIGHT   = 100;

  private:
    double get_max_tube_x ();
    double generate_tube_height ();
    void   generate_pair_of_tubes (double x, double top_tube_end_y, double bot_tube_end_y);
};

//--------------------------------------------------

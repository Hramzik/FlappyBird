
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/GameObject/GameObject.h"

//--------------------------------------------------

// despawns tubes behind anker
class TubeDespawner: public Component {

  public:
    TubeDespawner (GameObject& anker, std::vector<GameObject*>& tubes);
    void act (double dt) override;

  private:
    GameObject&               anker_;
    std::vector<GameObject*>& tubes_;

  private:
    static constexpr double DESPAWN_RADIUS = 500;

  private:
    double get_max_tube_x ();
};

//--------------------------------------------------

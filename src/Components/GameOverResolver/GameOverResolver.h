
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/GameObject/GameObject.h"
#include "src/Texture/Texture.h"

//--------------------------------------------------

class GameOverResolver: public Component {

  public:
    void observe (GameObject& player);
    void act (double dt) override;

  private:
    GameObject* player_ = nullptr;
};
//--------------------------------------------------

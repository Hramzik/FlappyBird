
//--------------------------------------------------

#pragma once

#include "src/Screen/Screen.h"
#include "src/GameObject/GameObject.h"
#include "src/GameFactory/GameFactory.h"

//--------------------------------------------------

class GameMaster {

  public:
    GameMaster(Screen& screen);
    Screen&                   get_screen  ();
    std::vector<GameObject*>& get_objects ();

    void initialize ();
    void act (double dt);
    void draw ();

  private:
    Screen& screen_;
    std::vector<GameObject*> objects_;
    GameFactory& factory_;
};

//--------------------------------------------------


//--------------------------------------------------

#pragma once

#include "src/GameObject/GameObject.h"
#include "src/Vector2/Vector2.h"

//--------------------------------------------------

class GameMaster;

//--------------------------------------------------

class GameFactory {

  public:
    GameFactory (GameMaster& master);
    void place_at_game_master (GameObject& object);
    GameObject& create_player ();
    GameObject& create_tube_gen (GameObject& anker);
    GameObject& create_tube (Vector2<double> edge, bool is_bottom);
    GameObject& create_background ();

  private:
    GameMaster& game_master_;
};
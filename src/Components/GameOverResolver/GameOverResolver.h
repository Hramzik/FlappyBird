
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/GameMaster/GameMaster.h"
#include "src/GameObject/GameObject.h"
#include "src/Texture/Texture.h"

//--------------------------------------------------

class GameOverResolver: public Component {

  public:
    GameOverResolver (GameMaster& master);
    void observe (GameObject& player);
    void act (double dt) override;

    void try_end_game ();
    void end_game ();
    void try_restart_game ();
    void restart_game ();

  private:
    GameObject* player_ = nullptr;
    GameMaster& game_master_;
    bool game_over_ = false;

  private:
    static constexpr int RESTART_GAME_KEY = VK_SPACE;
};
//--------------------------------------------------


//--------------------------------------------------

#pragma once

#include "src/Screen/Screen.h"
#include "src/GameObject/GameObject.h"
#include "src/GameFactory/GameFactory.h"
#include "src/TextureStorage/TextureStorage.h"

//--------------------------------------------------

class GameMaster {

  public:
    GameMaster  (Screen& screen);
    ~GameMaster ();
    Screen&                   get_screen  ();
    std::vector<GameObject*>& get_objects ();
    void restart_game ();

    void initialize ();
    void act (double dt);
    void draw ();

  private:
    Screen& screen_;
    std::vector<GameObject*> objects_;
    TextureStorage texture_storage_;
    GameObject* background_ = nullptr;
    GameFactory* factory_   = nullptr;

  private:
    void create_scene ();
    void clear_scene ();
};

//--------------------------------------------------

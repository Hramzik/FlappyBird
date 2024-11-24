
//--------------------------------------------------

#pragma once

#include "src/GameObject/GameObject.h"
#include "src/Vector2/Vector2.h"
#include "src/Components/Camera/Camera.h"

//--------------------------------------------------

class GameMaster;
class LifeResolver;
class CollisionManager;
class TextureStorage;

//--------------------------------------------------

class GameFactory {

  public:
    GameFactory (GameMaster& master, TextureStorage& storage);
    void place_at_game_master (GameObject& object);
    GameObject& create_main_camera ();
    GameObject& create_background_camera ();
    GameObject& create_player ();
    GameObject& create_tube (Vector2<double> edge, bool is_bottom);
    GameObject& create_background ();

    GameObject& create_collision_manager ();
    GameObject& create_tube_gen       (GameObject& anker);
    GameObject& create_tube_despawner (GameObject& anker);
    GameObject& create_game_over ();

    GameObject& create_fps_counter ();

  private:
    GameMaster&     game_master_;
    TextureStorage& texture_storage_;

    CollisionManager* collision_manager_ = nullptr;
    Camera*     main_camera_       = nullptr;
    Camera*     background_camera_ = nullptr;
    GameObject* main_camera_obj_ = nullptr;
    GameObject* player_ = nullptr;
};

//--------------------------------------------------

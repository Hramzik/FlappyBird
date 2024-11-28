
//--------------------------------------------------

#include <iostream>
#include <stdexcept>

#include "GameFactory.h"
#include "src/GameMaster/GameMaster.h"
#include "src/TextureStorage/TextureStorage.h"
#include "src/Components/Player/PlayerController.h"
#include "src/Components/Player/PlayerCollider.h"
#include "src/Components/BorderKillResolver/BorderKillResolver.h"
#include "src/Components/FollowerLinker/FollowerLinker.h"
#include "src/Components/Tube/Tube.h"
#include "src/Components/TubeGenerator/TubeGenerator.h"
#include "src/Components/TubeDespawner/TubeDespawner.h"
#include "src/Components/Collisions/CollisionManager.h"
#include "src/Components/HitboxRenderer/HitboxRenderer.h"
#include "src/Components/GameOverResolver/GameOverResolver.h"
#include "src/Components/Rigidbody/Rigidbody.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/TextureRenderer/TextureRenderer.h"
#include "src/Components/LifeResolver/LifeResolver.h"
#include "src/Components/FpsCounter/FpsCounter.h"
#include "src/ImageLoader/ImageLoader.h"
#include "src/TextureResizer/TextureResizer.h"

//--------------------------------------------------

GameFactory::GameFactory (GameMaster& master, TextureStorage& storage):
        game_master_     (master),
        texture_storage_ (storage) {}

void GameFactory::place_at_game_master (GameObject& object) {

    game_master_.get_objects ().push_back (&object);
}

GameObject& GameFactory::create_main_camera () {

    Component& transform = *new Transform (0);
    Camera&    camera    = *new Camera (game_master_.get_screen ());

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (transform);
    obj.add_component (camera);

    //--------------------------------------------------

    main_camera_     = &camera;
    main_camera_obj_ = &obj;
    return obj;
}

GameObject& GameFactory::create_background_camera () {

    Component& transform = *new Transform (0);
    Camera&    camera    = *new Camera (game_master_.get_screen ());

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (transform);
    obj.add_component (camera);

    //--------------------------------------------------

    background_camera_ = &camera;
    return obj;
}

GameObject& GameFactory::create_player () {

    Component& controller = *new PlayerController ();
    Component& rb         = *new RigidBody ({PlayerController::DEFAULT_SPEED, 0});
    Component& transform  = *new Transform (100);

    Texture& texture = texture_storage_.get_texture ("media/bird.png");
    TextureResizer::resize_texture(texture, {95, 70});
    Component& renderer = *new TextureRenderer (texture, *main_camera_);

    if (!main_camera_obj_) throw std::logic_error ("Create main camera before player");
    FollowerLinker& camera_linker = *new FollowerLinker (*main_camera_obj_);
    camera_linker.set_follower_offset (-300);
    camera_linker.set_follow_y (false);

    PlayerCollider& collider = *new PlayerCollider ();
    collider.add_box (CollisionBox ({10, 10}, {75, 50}));

    LifeResolver& player_life   = *new LifeResolver ();
    BorderKillResolver& player_killer = *new BorderKillResolver ();

    //--------------------------------------------------

    GameObject& player = *new GameObject ();
    player.add_component (controller);
    player.add_component (rb);
    player.add_component (transform);
    player.add_component (renderer);
    player.add_component (camera_linker);
    player.add_component (collider);
    player.add_component (player_life);
    player.add_component (player_killer);

    //--------------------------------------------------

    player_ = &player;
    return player;
}

GameObject& GameFactory::create_tube (Vector2<double> edge, bool is_bottom) {

    Component& tube = *new Tube ();

    Vector2<double> pos = is_bottom ? edge : edge + Vector2<double> (0, -500);
    Component& transform = *new Transform (pos);

    const char* img_path = is_bottom ? "media/tube-bottom.png" : "media/tube-top.png";
    Texture& texture = texture_storage_.get_texture(img_path);
    TextureResizer::resize_texture(texture, {100, 500});
    Component& renderer = *new TextureRenderer (texture, *main_camera_);

    Collider& collider = *new Collider ();
    collider.add_box (CollisionBox ({20, 20}, {60, 460}));

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (tube);
    obj.add_component (transform);
    obj.add_component (renderer);
    obj.add_component (collider);

    return obj;
}

GameObject& GameFactory::create_background () {

    Component& transform = *new Transform (0);

    Texture& texture = texture_storage_.get_texture("media/background.png");
    TextureResizer::resize_texture (texture, {SCREEN_WIDTH, SCREEN_HEIGHT});
    Component& renderer = *new TextureRenderer (texture, *background_camera_);

    //--------------------------------------------------

    GameObject& background = *new GameObject ();
    background.add_component (transform);
    background.add_component (renderer);

    //--------------------------------------------------

    return background;
}

//--------------------------------------------------

GameObject& GameFactory::create_collision_manager () {

    CollisionManager& manager = *new CollisionManager ();
    manager.observe (game_master_.get_objects ());

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (manager);

    //--------------------------------------------------

    return obj;
}

GameObject& GameFactory::create_tube_gen (GameObject& anker) {

    GameObject& obj = *new GameObject ();
    Component& tube_gen = *new TubeGenerator (anker, game_master_.get_objects (), *this);
    obj.add_component (tube_gen);

    return obj;
}

GameObject& GameFactory::create_tube_despawner (GameObject& anker) {

    GameObject& obj = *new GameObject ();
    Component& despawner = *new TubeDespawner (anker, game_master_.get_objects ());
    obj.add_component (despawner);

    return obj;
}

GameObject& GameFactory::create_game_over () {

    if (!player_) throw std::logic_error ("Create player before game over");

    //--------------------------------------------------

    Component& transform = *new Transform ({SCREEN_WIDTH / 2 - 370, SCREEN_HEIGHT / 2 - 300});

    Texture& texture = texture_storage_.get_texture ("media/game_over.png");
    TextureResizer::resize_texture(texture, {800, 600});
    Component& renderer = *new TextureRenderer (texture, *background_camera_);
    renderer.deactivate ();

    GameOverResolver& game_over = *new GameOverResolver (game_master_);
    game_over.observe (*player_);

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (transform);
    obj.add_component (renderer);
    obj.add_component (game_over);

    //--------------------------------------------------

    return obj;
}

//--------------------------------------------------

GameObject& GameFactory::create_fps_counter () {

    Component& counter = *new FpsCounter ();

    //--------------------------------------------------

    GameObject& obj = *new GameObject ();
    obj.add_component (counter);

    //--------------------------------------------------

    return obj;
}

//--------------------------------------------------


//--------------------------------------------------

#include <iostream>

#include "GameFactory.h"
#include "src/GameMaster/GameMaster.h"
#include "src/Components/PlayerController/PlayerController.h"
#include "src/Components/Tube/Tube.h"
#include "src/Components/TubeGenerator/TubeGenerator.h"
#include "src/Components/Rigidbody/Rigidbody.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/TextureRenderer/TextureRenderer.h"
#include "src/ImageLoader/ImageLoader.h"
#include "src/TextureResizer/TextureResizer.h"

//--------------------------------------------------

GameFactory::GameFactory (GameMaster& master):
        game_master_ (master) {}

void GameFactory::place_at_game_master (GameObject& object) {

    game_master_.get_objects ().push_back (&object);
}

GameObject& GameFactory::create_player () {

    Component& controller = *new PlayerController ();
    Component& rb         = *new RigidBody ({PlayerController::DEFAULT_SPEED, 0});
    Component& transform  = *new Transform (100);

    Texture& texture = Image_Loader::load_image("media/bird.png");
    TextureResizer::resize_texture(texture, {95, 70});
    Component& renderer = *new TextureRenderer (texture, game_master_.get_screen ());

    //--------------------------------------------------

    GameObject& player = *new GameObject ();
    player.add_component (controller);
    player.add_component (rb);
    player.add_component (transform);
    player.add_component (renderer);

    //--------------------------------------------------

    return player;
}

GameObject& GameFactory::create_tube (Vector2<double> edge, bool is_bottom) {

    Component& tube_comp = *new Tube ();

    Vector2<double> pos = is_bottom ? edge : edge + Vector2<double> (0, -500);
    Component& transform = *new Transform (pos);

    const char* img_path = is_bottom ? "media/tube-bottom.png" : "media/tube-top.png";
    Texture& texture = Image_Loader::load_image(img_path);
    TextureResizer::resize_texture(texture, {100, 500});
    Component& renderer = *new TextureRenderer (texture, game_master_.get_screen ());

    //--------------------------------------------------

    GameObject& tube = *new GameObject ();
    tube.add_component (tube_comp);
    tube.add_component (transform);
    tube.add_component (renderer);

    return tube;
}

GameObject& GameFactory::create_tube_gen (GameObject& anker) {

    GameObject& obj = *new GameObject ();
    Component& tube_gen = *new TubeGenerator (anker, game_master_.get_objects (), *this);
    obj.add_component (tube_gen);

    return obj;
}

GameObject& GameFactory::create_background () {

    Component& transform = *new Transform (0);

    Texture& texture = Image_Loader::load_image("media/background.png");
    TextureResizer::resize_texture(texture, {SCREEN_WIDTH, SCREEN_HEIGHT});
    Component& renderer = *new TextureRenderer (texture, game_master_.get_screen ());

    //--------------------------------------------------

    GameObject& background = *new GameObject ();
    background.add_component (transform);
    background.add_component (renderer);

    //--------------------------------------------------

    return background;
}

//--------------------------------------------------


//--------------------------------------------------

#include "GameOverResolver.h"
#include "src/Components/TextureRenderer/TextureRenderer.h"
#include "src/Components/LifeResolver/LifeResolver.h"
#include "src/Components/Player/PlayerController.h"
#include "src/Components/Rigidbody/Rigidbody.h"

//--------------------------------------------------

GameOverResolver::GameOverResolver (GameMaster& master):
        game_master_ (master) {}

void GameOverResolver::observe (GameObject& player) {

    player_ = &player;
}

void GameOverResolver::act (double dt) {

    if (!game_over_) try_end_game     ();
    else             try_restart_game ();
}

void GameOverResolver::try_end_game () {

    if (!player_) return;
    LifeResolver* player_life = player_->get_component<LifeResolver> ();
    if (!player_life) return;
    if (player_life->is_alive ()) return;

    //--------------------------------------------------

    end_game ();
}

void GameOverResolver::end_game () {

    //--------------------------------------------------
    // freeze player

    PlayerController* player_controller = player_->get_component<PlayerController> ();
    RigidBody*        player_rigidbody  = player_->get_component<RigidBody> ();
    if (player_controller) player_controller->deactivate ();
    if (player_rigidbody)  player_rigidbody->deactivate ();

    //--------------------------------------------------
    // show message

    if (!owner_) return;
    TextureRenderer* message = owner_->get_component<TextureRenderer> ();
    if (!message) return;
    message->activate ();

    //--------------------------------------------------
    // update flag

    game_over_ = true;
}

void GameOverResolver::try_restart_game () {

    if (!is_key_pressed (RESTART_GAME_KEY)) return;

    //--------------------------------------------------

    restart_game ();
}

void GameOverResolver::restart_game () {

    game_master_.restart_game ();
    game_over_ = false;
}

//--------------------------------------------------

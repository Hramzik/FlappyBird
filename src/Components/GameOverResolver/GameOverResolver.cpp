
//--------------------------------------------------

#include "GameOverResolver.h"
#include "src/Components/TextureRenderer/TextureRenderer.h"
#include "src/Components/LifeResolver/LifeResolver.h"
#include "src/Components/Player/PlayerController.h"
#include "src/Components/Rigidbody/Rigidbody.h"

//--------------------------------------------------

void GameOverResolver::observe (GameObject& player) {

    player_ = &player;
}

void GameOverResolver::act (double dt) {

    if (!player_) return;
    LifeResolver* player_life = player_->get_component<LifeResolver> ();
    if (!player_life) return;
    if (player_life->is_alive ()) return;

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
}

//--------------------------------------------------

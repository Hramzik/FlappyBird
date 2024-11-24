
//--------------------------------------------------

#include <iostream>
#include <sstream>
#include <windows.h>

#include "GameMaster.h"
#include "src/GameFactory/GameFactory.h"

//--------------------------------------------------

GameMaster::GameMaster(Screen& screen):
    screen_ (screen),
    objects_ (),
    factory_ (*new GameFactory (*this)) {}

Screen& GameMaster::get_screen () {

    return screen_;
}

std::vector<GameObject*>& GameMaster::get_objects () {

    return objects_;
}

//--------------------------------------------------

void GameMaster::initialize () {

    GameObject& background = factory_.create_background ();
    GameObject& player     = factory_.create_player ();
    GameObject& tube_gen   = factory_.create_tube_gen (player);
    objects_.push_back (&background);
    objects_.push_back (&player);
    objects_.push_back (&tube_gen);
}

void GameMaster::act (double dt) {

    for (GameObject* object : objects_) {

        object->act (dt);
    }
}

void GameMaster::draw () {

    for (GameObject* object : objects_) {

        object->draw ();
    }
}

//--------------------------------------------------

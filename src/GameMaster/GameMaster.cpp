
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

    GameObject& main_camera       = factory_.create_main_camera ();
    GameObject& background_camera = factory_.create_background_camera ();
    GameObject& background = factory_.create_background ();
    GameObject& player     = factory_.create_player ();
    GameObject& tube_gen   = factory_.create_tube_gen (player);
    objects_.push_back (&main_camera);
    objects_.push_back (&background_camera);
    objects_.push_back (&background);
    objects_.push_back (&player);
    objects_.push_back (&tube_gen);

    //--------------------------------------------------

    GameObject& fps_counter = factory_.create_fps_counter ();
    objects_.push_back (&fps_counter);
}

void GameMaster::act (double dt) {

    // for (GameObject* object : objects_) {

    //     object->act (dt);
    // }

    // генератор труб меняет этот вектор во время прохода по нему
    // поэтому итерироваться нужно именно по индексам
    // на это баг я потратил немало времени
    for (int i = 0; i < objects_.size (); ++i) {
    
        objects_ [i]->act (dt);
    }
}

void GameMaster::draw () {

    for (GameObject* object : objects_) {

        object->draw ();
    }
}

//--------------------------------------------------

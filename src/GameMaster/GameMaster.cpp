
//--------------------------------------------------

#include <iostream>
#include <sstream>
#include <windows.h>

#include "GameMaster.h"
#include "src/GameFactory/GameFactory.h"

//--------------------------------------------------

GameMaster::GameMaster(Screen& screen):
    screen_ (screen),
    objects_ () {}

GameMaster::~GameMaster () {

    clear_scene ();
}

Screen& GameMaster::get_screen () {

    return screen_;
}

std::vector<GameObject*>& GameMaster::get_objects () {

    return objects_;
}

//--------------------------------------------------

void GameMaster::initialize () {

    factory_ = new GameFactory (*this);
    create_scene ();
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

    if (background_) background_->draw ();

    for (int i = (int) objects_.size () - 1; i >= 0; --i) {

        objects_ [i]->draw ();
    }
}

//--------------------------------------------------

void GameMaster::create_scene () {

    GameObject& collision_manager = factory_->create_collision_manager ();
    GameObject& main_camera       = factory_->create_main_camera ();
    GameObject& background_camera = factory_->create_background_camera ();
    GameObject& background = factory_->create_background ();
    GameObject& player     = factory_->create_player ();
    GameObject& tube_gen   = factory_->create_tube_gen (player);
    GameObject& game_over  = factory_->create_game_over ();
    objects_.push_back (&collision_manager);
    objects_.push_back (&main_camera);
    objects_.push_back (&background_camera);
    objects_.push_back (&tube_gen);
    objects_.push_back (&game_over);
    objects_.push_back (&player);
    background_ = &background;

    //--------------------------------------------------

    GameObject& fps_counter = factory_->create_fps_counter ();
    objects_.push_back (&fps_counter);
}

void GameMaster::clear_scene () {

    delete background_;

    for (int i = 0; i < (int) objects_.size (); ++i) {

        delete (objects_ [i]);
    }

    objects_.clear ();
}

//--------------------------------------------------

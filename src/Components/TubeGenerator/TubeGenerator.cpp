
//--------------------------------------------------

#include <iostream>
#include <algorithm>

#include "TubeGenerator.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/Tube/Tube.h"
#include "src/RNG/RNG.h"
#include "Engine.h"

//--------------------------------------------------

TubeGenerator::TubeGenerator (GameObject& anker, std::vector<GameObject*>& tubes, GameFactory& factory):
        anker_   (anker),
        tubes_   (tubes),
        factory_ (factory) {}

void TubeGenerator::act (double dt) {

    double anker_x = anker_.get_component<Transform> ()->get_position ().x;
    double max_tube_x = get_max_tube_x ();
    double start_x = std::max (max_tube_x + GENERATION_STEP, MIN_TUBE_X);

    for (double x = start_x; x < anker_x + GENERATION_RADIUS; x += GENERATION_STEP) {

        double top_tube_height = generate_tube_height ();
        double bot_tube_height = SCREEN_HEIGHT - top_tube_height - VERTICAL_GAP;
        generate_pair_of_tubes (x, top_tube_height, SCREEN_HEIGHT - bot_tube_height);
    }
}


double TubeGenerator::get_max_tube_x () {

    double max_tube_x = 0;

    for (GameObject* obj : tubes_) {

        if (obj->get_component<Tube> () == nullptr) continue;
        double tube_x = obj->get_component<Transform> ()->get_position ().x;
        max_tube_x = std::max (max_tube_x, tube_x);
    }

    return max_tube_x;
}

double TubeGenerator::generate_tube_height () {

    double min_height = MIN_TUBE_HEIGHT;
    double max_height = SCREEN_HEIGHT - MIN_TUBE_HEIGHT - VERTICAL_GAP;
    double height = RandomNumberGenerator::generate_between (min_height, max_height);

    return height;
}

void TubeGenerator::generate_pair_of_tubes (double x, double top_tube_end_y, double bot_tube_end_y) {

    GameObject& top_tube = factory_.create_tube (Vector2<double> (x, top_tube_end_y), false);
    GameObject& bot_tube = factory_.create_tube (Vector2<double> (x, bot_tube_end_y), true);
    factory_.place_at_game_master (top_tube);
    factory_.place_at_game_master (bot_tube);
}

//--------------------------------------------------

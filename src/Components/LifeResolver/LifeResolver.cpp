
//--------------------------------------------------

#include <iostream>

#include "LifeResolver.h"

//--------------------------------------------------

bool LifeResolver::is_alive () {

    return is_alive_;
}

void LifeResolver::kill () {

    std::cout << "DEAD" << "\n";
    is_alive_ = false;
}

//--------------------------------------------------

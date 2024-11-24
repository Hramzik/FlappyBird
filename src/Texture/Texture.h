
//--------------------------------------------------

#pragma once

#include <vector>

#include "src/Vector2/Vector2.h"
#include "src/Color/Color.h"

//--------------------------------------------------

struct Texture {

    Texture (Vector2<int> size, std::vector<Color> pixels);
    Color get_pixel(Vector2<int> pos) const;

    //--------------------------------------------------

    Vector2<int> size;
    std::vector<Color> pixels;
};

//--------------------------------------------------

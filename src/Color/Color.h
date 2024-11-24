
//--------------------------------------------------

#pragma once

#include <cstdint>

//--------------------------------------------------

struct Color {

    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

    Color (uint32_t pixel);
    Color (unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    Color (unsigned char r, unsigned char g, unsigned char b);
    Color ();
    operator uint32_t ();

    Color blend_on (Color background);
};

//--------------------------------------------------


//--------------------------------------------------

#include "Engine.h"

#include "Screen.h"

//--------------------------------------------------

Screen::Screen(Buffer& buffer):
        buffer_ (buffer) {}

//--------------------------------------------------

void Screen::render (Texture& texture, Vector2<int> pos) {

    int start_x = std::max(0, pos.x);
    int start_y = std::max(0, pos.y);
    int end_x   = std::min(SCREEN_WIDTH,  pos.x + texture.size.x);
    int end_y   = std::min(SCREEN_HEIGHT, pos.y + texture.size.y);

    for (int y = start_y; y < end_y; ++y) {
    for (int x = start_x; x < end_x; ++x) {
            int texture_x = x - pos.x;
            int texture_y = y - pos.y;

            buffer_[y][x] = texture.get_pixel({texture_x, texture_y}).blend_on (buffer_[y][x]);
        }
    }
}

//--------------------------------------------------

void Screen::draw (Vector2<int> pixel, uint32_t color) {

    int x = pixel.x;
    int y = pixel.y;

    buffer_[y][x] = color;
}

//--------------------------------------------------

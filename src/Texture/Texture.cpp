
//--------------------------------------------------

#include <stdexcept>

#include "Texture.h"

//--------------------------------------------------

Texture::Texture (Vector2<int> size, std::vector<Color> pixels):
        size   (size),
        pixels (pixels) {}

Color Texture::get_pixel(Vector2<int> pos) const {

    if (pos.x < 0 || pos.x >= size.x ||
        pos.y < 0 || pos.y >= size.y) {
        throw std::out_of_range ("Pixel coordinates are out of bounds");
    }

    int pixel_index = pos.y * size.x + pos.x;
    return pixels[pixel_index];
}

//--------------------------------------------------

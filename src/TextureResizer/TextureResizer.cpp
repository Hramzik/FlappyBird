
//--------------------------------------------------

#include <iostream>
#include <vector>

#include "lib/stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "lib/stb_image_resize2.h"

#include "TextureResizer.h"

//--------------------------------------------------

namespace TextureResizer {

void resize_texture (Texture& texture, Vector2<int> new_size) {

    std::vector<Color> resized_pixels (new_size.x * new_size.y);

    //--------------------------------------------------

    stbir_resize_uint8_linear ((unsigned char *) texture.pixels.data(), texture.size.x, texture.size.y, 0,
                               (unsigned char *) resized_pixels.data(), new_size.x,     new_size.y,     0,
                               (stbir_pixel_layout) 4);

    //--------------------------------------------------

    texture.size   = new_size;
    texture.pixels = resized_pixels;
}
} // namespace TextureResizer

//--------------------------------------------------

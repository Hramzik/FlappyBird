
//--------------------------------------------------

#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>

#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"

#include "ImageLoader.h"

//--------------------------------------------------

namespace Image_Loader {

Texture load_image(const std::string& filepath) {


    int width, height, channel_count;
    unsigned char* img = stbi_load(filepath.c_str(), &width, &height, &channel_count, 0);

    if (img == nullptr) {
        throw std::runtime_error ("Error while loading image");
    }

    //--------------------------------------------------

    std::vector<unsigned char> rgb_values (img, img + width * height * channel_count);
    ensure_alpha_channel_exists (rgb_values, channel_count);

    std::vector<Color> pixels = format_buffer (rgb_values);

    //--------------------------------------------------

    stbi_image_free(img);
    return Texture ({width, height}, pixels);
}

void ensure_alpha_channel_exists (std::vector<unsigned char>& pixels, int channel_count) {

    if (channel_count != 3) return;

    //--------------------------------------------------

    int pixel_count = (int) pixels.size () / 3;

    // Convert RGB to RGBA
    pixels.resize(pixel_count * 4);

    for (int i = pixel_count - 1; i >= 0; --i) {
        pixels[i * 4 + 3] = 255;
        pixels[i * 4 + 2] = pixels[i * 3 + 2];
        pixels[i * 4 + 1] = pixels[i * 3 + 1];
        pixels[i * 4] = pixels[i * 3];
    }
}

std::vector<Color> format_buffer (std::vector<unsigned char>& rgba_values) {

    std::vector<Color> pixels (rgba_values.size () / 4);

    for (int i = 0; i < pixels.size(); ++i) {
        pixels[i] = Color (rgba_values [i * 4 + 0], rgba_values [i * 4 + 1], rgba_values [i * 4 + 2], rgba_values [i * 4 + 3]);
    }

    return pixels;
}
} // namespace Image_Loader

//--------------------------------------------------

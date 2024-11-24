
//--------------------------------------------------

#pragma once

#include <vector>
#include <string>

#include "src/Texture/Texture.h"

//--------------------------------------------------

namespace Image_Loader {

    Texture& load_image (const std::string& filepath);
    void ensure_alpha_channel_exists (std::vector<unsigned char>& pixels, int channel_count);
    std::vector<Color> format_buffer (std::vector<unsigned char>& rgba_values);
}

//--------------------------------------------------

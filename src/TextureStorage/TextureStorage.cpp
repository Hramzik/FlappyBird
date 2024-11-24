
//--------------------------------------------------

#include "TextureStorage.h"
#include "src/ImageLoader/ImageLoader.h"

//--------------------------------------------------

TextureStorage::TextureStorage ():
        textures_ () {}

Texture& TextureStorage::get_texture (const char* path) {

    auto it = textures_.find (path);
    if (it != textures_.end()) return *new Texture (*it->second);

    Texture& new_texture = Image_Loader::load_image(path);
    textures_ [path] = &new_texture;
    return new_texture;
}

//--------------------------------------------------

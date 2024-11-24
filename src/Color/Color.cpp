
//--------------------------------------------------

#include "Color.h"

//--------------------------------------------------

Color::Color (uint32_t pixel):
        r ((pixel >> 16) & 0xFF),
        g ((pixel >> 8)  & 0xFF),
        b ((pixel >> 0)  & 0xFF),
        a ((pixel >> 24) & 0xFF) {}

Color::Color (unsigned char r, unsigned char g, unsigned char b, unsigned char a):
    r (r),
    g (g),
    b (b),
    a (a) {}

Color::Color (unsigned char r, unsigned char g, unsigned char b):
    Color (r, g, b, 255) {}

Color::Color ():
    Color (248, 24, 148, 255) {}

Color::operator uint32_t () {

    uint32_t pixel = 0;
    pixel |= static_cast<uint32_t> (a) << 24;
    pixel |= static_cast<uint32_t> (r) << 16;
    pixel |= static_cast<uint32_t> (g) << 8;
    pixel |= static_cast<uint32_t> (b) << 0;

    return pixel;
}

Color Color::blend_on (Color background) {

    if (background.a == 0) return *this;
    if (a > 250)  return *this;
    if (a == 0)   return background;

    //--------------------------------------------------

    double src_alpha = a / 255;
    double dst_alpha = background.a / 255;
    double out_alpha = src_alpha + dst_alpha * (1 - src_alpha);

    double inv_out_alpha = 1 / out_alpha;

    unsigned char blended_r = static_cast<unsigned char> ((r * src_alpha + background.r * dst_alpha * (1 - src_alpha)) * inv_out_alpha);
    unsigned char blended_g = static_cast<unsigned char> ((g * src_alpha + background.g * dst_alpha * (1 - src_alpha)) * inv_out_alpha);
    unsigned char blended_b = static_cast<unsigned char> ((b * src_alpha + background.b * dst_alpha * (1 - src_alpha)) * inv_out_alpha);
    unsigned char blended_a = static_cast<unsigned char> (out_alpha * 255);

    return Color (blended_r, blended_g, blended_b, blended_a);
}

//--------------------------------------------------

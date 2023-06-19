/* vim: set ai et ts=4 sw=4: */
#ifndef __FONTS_H__
#define __FONTS_H__

#include <stdint.h>

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} TFT_FontDef;


extern TFT_FontDef TFT_Font_7x10;
extern TFT_FontDef TFT_Font_11x18;
extern TFT_FontDef TFT_Font_16x26;

#endif // __FONTS_H__

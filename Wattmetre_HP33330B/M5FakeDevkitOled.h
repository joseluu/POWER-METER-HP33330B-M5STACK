#pragma once
#ifndef M5FAKEDEVKITOLED_H
#define M5FAKEDEVKITOLED_H
#include <SSD1306Wire.h>

#define TFT_BLACK       0x0000 /*   0,   0,   0 */
#define TFT_NAVY        0x000F /*   0,   0, 128 */
#define TFT_DARKGREEN   0x03E0 /*   0, 128,   0 */
#define TFT_DARKCYAN    0x03EF /*   0, 128, 128 */
#define TFT_MAROON      0x7800 /* 128,   0,   0 */
#define TFT_PURPLE      0x780F /* 128,   0, 128 */
#define TFT_OLIVE       0x7BE0 /* 128, 128,   0 */
#define TFT_LIGHTGREY   0xC618 /* 192, 192, 192 */
#define TFT_DARKGREY    0x7BEF /* 128, 128, 128 */
#define TFT_BLUE        0x001F /*   0,   0, 255 */
#define TFT_GREEN       0x07E0 /*   0, 255,   0 */
#define TFT_CYAN        0x07FF /*   0, 255, 255 */
#define TFT_RED         0xF800 /* 255,   0,   0 */
#define TFT_MAGENTA     0xF81F /* 255,   0, 255 */
#define TFT_YELLOW      0xFFE0 /* 255, 255,   0 */
#define TFT_WHITE       0xFFFF /* 255, 255, 255 */
#define TFT_ORANGE      0xFDA0 /* 255, 180,   0 */
#define TFT_GREENYELLOW 0xB7E0 /* 180, 255,   0 */
#define TFT_PINK        0xFC9F

#ifndef M5FAKEDEVKITOLED_IMPL
#define BLUE TFT_BLUE
#define YELLOW TFT_YELLOW
#define BLACK TFT_BLACK
#endif

class M5FakeDevkitOled{
   public:
M5FakeDevkitOled(): oled(0x3c, SDA_OLED, SCL_OLED, GEOMETRY_128_64, I2C_TWO)
    {};
    virtual ~M5FakeDevkitOled()
    {};
    void begin();
    void test();
    void fillScreen(int color);
    void fillRect(int32_t x, int32_t y,
             int32_t w, int32_t h, int color);
    void setTextColor(int fgcolor);
    void setTextColor(int fgcolor, int bgcolor);
    uint16_t drawString(
            const char *string, int32_t dX, int32_t poY,
            uint8_t font);
    uint16_t drawCentreString(
            const char *string, int32_t dX, int32_t poY,
            uint8_t font);
    uint16_t drawCentreString(const String &string, int32_t dX,
                                                int32_t poY, uint8_t font);
    void drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1,
             int color);
    void drawRect(int32_t x0, int32_t y0, int32_t x1, int32_t y1,
             int color);
private:
    SSD1306Wire oled;
    void oledSetup();
    OLEDDISPLAY_COLOR defaultColor;
    OLEDDISPLAY_COLOR convertColor(int color);
    uint16_t drawStringInternal(
            const char *string, int32_t dX, int32_t poY,
            uint8_t font, OLEDDISPLAY_TEXT_ALIGNMENT textAlignment);
    int fgcolorText;
    int bgcolorText; 
};

#endif

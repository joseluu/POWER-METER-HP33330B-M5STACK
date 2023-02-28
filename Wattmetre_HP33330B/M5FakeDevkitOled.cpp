#define M5FAKEDEVKITOLED_IMPL
#include "M5FakeDevkitOled.h"


#define RESCALE_X(x) (x/2-15)
#define RESCALE_Y(y) (y/2-7)
#define RESCALE(d) (d/2)

void M5FakeDevkitOled::oledSetup() {
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(50);
  digitalWrite(OLED_RST, HIGH);

  oled.init();
  oled.clear();
  defaultColor=WHITE;
  oled.flipScreenVertically();
  oled.setFont(ArialMT_Plain_10);
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
  oled.drawString(0 , 0, "OLED INIT" );
  oled.display();
}


void M5FakeDevkitOled::begin(){
    oledSetup();
}

void  M5FakeDevkitOled::test(){
      oled.drawString(0 , 10, "TEST" );
      oled.display();
}

OLEDDISPLAY_COLOR M5FakeDevkitOled::convertColor(int color){
    if (color == 0x0000) {
        return BLACK;
    }
    if (color == TFT_MAGENTA) {
        return BLACK;
    }
    return WHITE;
}

void M5FakeDevkitOled::fillRect(int32_t x, int32_t y,
                           int32_t w, int32_t h, int color){
    OLEDDISPLAY_COLOR oldColor = oled.getColor();
    oled.setColor(convertColor(color));
    oled.fillRect(RESCALE_X(x), RESCALE_Y(y), RESCALE(w), RESCALE(h));
    oled.setColor(oldColor);
    oled.display();
}

void M5FakeDevkitOled::fillScreen(int color){
    fillRect(0, 0,// 128, 64, color);
             oled.getWidth(), oled.getHeight(), color);
}

void M5FakeDevkitOled::drawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1,
                int color){
    OLEDDISPLAY_COLOR oldColor = oled.getColor();
    oled.setColor(convertColor(color));
    oled.drawLine(RESCALE_X(x0), RESCALE_Y(y0), RESCALE_X(x1), RESCALE_Y(y1));
    oled.setColor(oldColor);
    oled.display();
}

void M5FakeDevkitOled::drawRect(int32_t x0, int32_t y0, int32_t x1, int32_t y1,
                                int color){
    OLEDDISPLAY_COLOR oldColor = oled.getColor();
    oled.setColor(convertColor(color));
    oled.drawRect(RESCALE_X(x0), RESCALE_Y(y0), RESCALE_X(x1), RESCALE_Y(y1));
    oled.setColor(oldColor);
    oled.display();
}


uint16_t M5FakeDevkitOled::drawStringInternal(const char *string,
                                          int32_t dX, int32_t poY,
                                          uint8_t font,
                                          OLEDDISPLAY_TEXT_ALIGNMENT
                                          textAlignment ){
    uint16_t baselineOffset;
    uint16_t fontHeight;
    switch (font){
    case 3:
          oled.setFont(ArialMT_Plain_16);
          baselineOffset = 4;
          fontHeight = 16;
        break;
    case 2:
    default:
          oled.setFont(ArialMT_Plain_10);
          baselineOffset = 2;
          fontHeight = 10;
    }
    uint16_t width = oled.getStringWidth(string);
    uint16_t xStart =0;
    switch (textAlignment) {
    case TEXT_ALIGN_CENTER:
        xStart=RESCALE_X(dX)-width/2;
    case TEXT_ALIGN_LEFT:
        xStart=RESCALE_X(dX);
    }
    oled.setTextAlignment(textAlignment);
    OLEDDISPLAY_COLOR oldColor = oled.getColor();
    oled.setColor(convertColor(bgcolorText));
    oled.fillRect(xStart, RESCALE_Y(poY), width, fontHeight);
    oled.setColor(convertColor(fgcolorText));
    oled.drawString(RESCALE_X(dX), RESCALE_Y(poY), string);
    oled.setColor(oldColor);
    oled.display();
    return width;
}

uint16_t M5FakeDevkitOled::drawString(const char *string,
                                   int32_t dX, int32_t poY,
                                          uint8_t font){
    return drawStringInternal(string, dX, poY, font, TEXT_ALIGN_LEFT);
}

uint16_t M5FakeDevkitOled::drawCentreString(const char *string,
                                   int32_t dX, int32_t poY,
                                          uint8_t font){
    return drawStringInternal(string, dX, poY, font, TEXT_ALIGN_CENTER);
}

uint16_t M5FakeDevkitOled::drawCentreString(const String &string, int32_t dX,
                                   int32_t poY, uint8_t font) {
    int16_t len = string.length() + 2;
    char buffer[len];
    string.toCharArray(buffer, len);
    return drawCentreString(buffer, dX, poY, font);
}

void M5FakeDevkitOled::setTextColor(int fgcolor, int bgcolor){
    fgcolorText=fgcolor;
    bgcolorText=bgcolor;
}

void M5FakeDevkitOled::setTextColor(int fgcolor){
    fgcolorText=fgcolor;
    bgcolorText=~fgcolor;
}

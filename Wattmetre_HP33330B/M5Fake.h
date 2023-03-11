#pragma once
#ifndef M5FAKE_H
#define M5FAKE_H
#include "M5FakeDevkitOled.h"
#include "Button.h"

#define BUTTON_A_PIN 0
#define BUTTON_B_PIN 34
#define BUTTON_C_PIN 12

class M5Fake {
public:
    M5Fake(){};
    void begin();
    void update();
    M5FakeDevkitOled Lcd;
    #define DEBOUNCE_TIME_MS 10
    Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_TIME_MS);
    Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_TIME_MS);
    Button BtnC = Button(BUTTON_C_PIN, true, DEBOUNCE_TIME_MS);
};

#define lcd Lcd

extern M5Fake M5;

#endif

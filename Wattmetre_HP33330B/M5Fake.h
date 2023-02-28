#pragma once
#ifndef M5FAKE_H
#define M5FAKE_H
#include "M5FakeDevkitOled.h"

class ButtonFake {
public:
    bool wasPressed() {
        return false;
    }
    bool isPressed() {
        return false;
    }
};

class M5Fake {
public:
    M5Fake(){};
    void begin();
    void update() {};
    M5FakeDevkitOled Lcd;
    ButtonFake BtnA;
    ButtonFake BtnB;
    ButtonFake BtnC;
};

#define lcd Lcd

extern M5Fake M5;

#endif

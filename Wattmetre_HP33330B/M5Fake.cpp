#include "M5Fake.h"

M5Fake M5;
void M5Fake::begin() {
    lcd.begin();
}

void M5Fake::update() {
    // update buttons
    BtnA.read();
    BtnB.read();
    BtnC.read();
}

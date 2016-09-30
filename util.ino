/* Utility Functions for Dorm LEDs */

void setAllWindowPixelColor(uint16_t index, uint32_t color){
    window1.setPixelColor(index, color);
    window2.setPixelColor(index, color);
    window3.setPixelColor(index, color);
}

void showAllWindowStrips(){
    window1.show();
    window2.show();
    window3.show();
}


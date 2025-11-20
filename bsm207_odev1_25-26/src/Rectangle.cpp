#include "Rectangle.hpp"

Rectangle::Rectangle(int xPos, int yPos, int s, char c, int zIndex)
    : Shape(xPos, yPos, s, c, zIndex) {}

Rectangle::~Rectangle() {}

void Rectangle::draw(char screen[25][80]) {
    // Dolu dikdörtgen çizimi
    int width = size * 2;  // Genişlik yüksekliğin 2 katı
    int height = size;
    
    for (int i = 0; i < height && (y + i) < 25; i++) {
        for (int j = 0; j < width && (x + j) < 80; j++) {
            int px = x + j;
            int py = y + i;
            // SOL SINIR: px >= 12 (kutu listesi 0-11 arası)
            if (px >= 12 && px < 80 && py >= 0 && py < 25) {
                screen[py][px] = drawChar;
            }
        }
    }
}

string Rectangle::getTypeName() const {
    return "Rectangle";
}

int Rectangle::getTypeId() const {
    return 1;
}
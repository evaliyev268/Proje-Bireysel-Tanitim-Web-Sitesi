#include "Triangle.hpp"

Triangle::Triangle(int xPos, int yPos, int s, char c, int zIndex)
    : Shape(xPos, yPos, s, c, zIndex) {}

Triangle::~Triangle() {}

void Triangle::draw(char screen[25][80]) {
    // Dolu üçgen çizimi (yukarıdan aşağıya genişleyen)
    for (int i = 0; i < size && i < 10; i++) {
        for (int j = 0; j <= i * 2; j++) {
            int px = x + j - i;
            int py = y + i;
            // SOL SINIR: px >= 12 (kutu listesi 0-11 arası)
            if (px >= 12 && px < 80 && py >= 0 && py < 25) {
                screen[py][px] = drawChar;
            }
        }
    }
}

string Triangle::getTypeName() const {
    return "Triangle";
}

int Triangle::getTypeId() const {
    return 0;
}
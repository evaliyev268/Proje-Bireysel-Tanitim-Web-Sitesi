#include "Star.hpp"

Star::Star(int xPos, int yPos, int s, char c, int zIndex)
    : Shape(xPos, yPos, s, c, zIndex) {}

Star::~Star() {}

void Star::draw(char screen[25][80]) {
    // Baklava/Elmas şeklinde yıldız çizimi
    
    int halfSize = size / 2;
    
    // ÜST KISIM - Yukarıdan ortaya doğru genişleyen
    for (int i = 0; i <= halfSize; i++) {
        for (int j = -i; j <= i; j++) {
            int px = x + j;
            int py = y + i;
            // SOL SINIR: px >= 12 (kutu listesi 0-11 arası)
            if (px >= 12 && px < 80 && py >= 0 && py < 25) {
                screen[py][px] = drawChar;
            }
        }
    }
    
    // ALT KISIM - Ortadan aşağıya doğru daralan
    for (int i = halfSize + 1; i < size; i++) {
        int width = size - i - 1;
        for (int j = -width; j <= width; j++) {
            int px = x + j;
            int py = y + i;
            // SOL SINIR: px >= 12 (kutu listesi 0-11 arası)
            if (px >= 12 && px < 80 && py >= 0 && py < 25) {
                screen[py][px] = drawChar;
            }
        }
    }
}

string Star::getTypeName() const {
    return "Star";
}

int Star::getTypeId() const {
    return 2;
}
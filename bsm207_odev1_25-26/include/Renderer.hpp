#ifndef RENDERER_HPP
#define RENDERER_HPP

// ÖNCE C++ standart kütüphanelerini include et
#include "BoxList.hpp"
#include <iostream>
#include <string>

// SONRA Windows.h'yi include et
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#undef min
#undef max

class Renderer {
private:
    char screen[25][80];
    char oldScreen[25][80];
    HANDLE hConsole;
    COORD coord;
    
    void clearScreen();
    void setCursorPosition(int x, int y);
    void hideCursor();
    
public:
    Renderer();
    
    void render(BoxList* boxes, int selectedBoxIndex, int selectedShapeIndex, bool insideBox, int scrollOffset);
    void drawBoxList(BoxList* boxes, int selectedIndex, int scrollOffset);
    void drawShapes(Box* box, int selectedShapeIndex);
    void drawControls(bool insideBox);
    void drawScrollIndicator(int currentPos, int totalBoxes);
    void display();
    
    void setPixel(int x, int y, char c);
};

#endif
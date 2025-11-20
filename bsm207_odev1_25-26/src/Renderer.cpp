#include "Renderer.hpp"
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

Renderer::Renderer() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = 0;
    coord.Y = 0;
    
    hideCursor();
    
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            screen[y][x] = ' ';
            oldScreen[y][x] = ' ';
        }
    }
}

void Renderer::hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Renderer::setCursorPosition(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void Renderer::clearScreen() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            screen[y][x] = ' ';
        }
    }
}

void Renderer::setPixel(int x, int y, char c) {
    if (x >= 0 && x < 80 && y >= 0 && y < 25) {
        screen[y][x] = c;
    }
}

void Renderer::drawBoxList(BoxList* boxes, int selectedIndex, int scrollOffset) {
    if (!boxes) return;
    
    const int MAX_VISIBLE_BOXES = 7;
    
    BoxNode* current = boxes->getHead();
    
    // ScrollOffset kadar ilerle
    for (int i = 0; i < scrollOffset && current; i++) {
        current = current->next;
    }
    
    int displayIndex = scrollOffset;
    int yPos = 0;
    int boxesDrawn = 0;
    
    // Sadece mevcut sayfadaki kutuları çiz
    while (current && boxesDrawn < MAX_VISIBLE_BOXES) {
        // Kutu çerçevesi üst
        for (int i = 0; i < 10; i++) {
            setPixel(i, yPos, '*');
        }
        
        // Kutu içeriği
        if (displayIndex == selectedIndex) {
            setPixel(1, yPos + 1, '>');
            setPixel(9, yPos + 1, '<');
        } else {
            setPixel(0, yPos + 1, '*');
            setPixel(9, yPos + 1, '*');
        }
        
        // Şekil sayısı (ortada)
        int count = current->box->getShapeCount();
        string countStr = to_string(count);
        int xStart = 5 - countStr.length() / 2;
        for (size_t i = 0; i < countStr.length(); i++) {
            setPixel(xStart + i, yPos + 1, countStr[i]);
        }
        
        // Kutu çerçevesi alt
        for (int i = 0; i < 10; i++) {
            setPixel(i, yPos + 2, '*');
        }
        
        current = current->next;
        displayIndex++;
        yPos += 3;
        boxesDrawn++;
    }
}

void Renderer::drawScrollIndicator(int currentPos, int totalBoxes) {
    // BOŞ - Sayfa göstergesi kaldırıldı
}

void Renderer::drawShapes(Box* box, int selectedShapeIndex) {
    if (!box) return;
    
    ShapeList* shapes = box->getShapes();
    ShapeNode* current = shapes->getHead();
    
    int index = 0;
    while (current) {
        Shape* shape = current->shape;
        
        // Seçili şekli vurgula
        if (index == selectedShapeIndex) {
            int shapeX = shape->getX();
            int shapeY = shape->getY();
            
            // SOL köşeli parantez (sadece sağ alanda, x >= 12)
            if (shapeX > 12) {  // 12'den büyük olmalı (en az 13)
                setPixel(shapeX - 1, shapeY, '[');
            }
            
            // SAĞ köşeli parantez
            if (shapeX + shape->getSize() + 1 < 80) {
                setPixel(shapeX + shape->getSize() + 1, shapeY, ']');
            }
        }
        
        // POLİMORFİZM - Her şekil kendi draw() metodunu çağırır
        shape->draw(screen);
        
        current = current->next;
        index++;
    }
}

void Renderer::drawControls(bool insideBox) {
    string controls;
    if (insideBox) {
        controls = "(e/g) sekil sec (wasd) hareket (c) sil (esc) cik (q) kaydet&cik";
    } else {
        controls = "(w/s) sayfa degistir (f) kutuya gir (c) kutu sil (q) kaydet&cik";
    }
    
    int xStart = 0;
    for (size_t i = 0; i < controls.length() && xStart < 80; i++) {
        setPixel(xStart++, 24, controls[i]);
    }
}

void Renderer::render(BoxList* boxes, int selectedBoxIndex, int selectedShapeIndex, bool insideBox, int scrollOffset) {
    clearScreen();
    
    // Sol taraf - Kutu listesi (0-11 arası)
    drawBoxList(boxes, selectedBoxIndex, scrollOffset);
    
    // Scroll göstergesi (kaldırıldı)
    // drawScrollIndicator(selectedBoxIndex, boxes->getCount());
    
    // Sağ taraf - Seçili kutunun şekilleri (12-79 arası)
    Box* selectedBox = boxes->getBox(selectedBoxIndex);
    if (selectedBox) {
        drawShapes(selectedBox, insideBox ? selectedShapeIndex : -1);
    }
    
    // Alt kısım - Kontroller (satır 24)
    drawControls(insideBox);
    
    display();
}

void Renderer::display() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (screen[y][x] != oldScreen[y][x]) {
                setCursorPosition(x, y);
                cout << screen[y][x];
                oldScreen[y][x] = screen[y][x];
            }
        }
    }
    cout.flush();
}
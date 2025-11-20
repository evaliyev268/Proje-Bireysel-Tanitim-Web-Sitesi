#include "Box.hpp"
#include <cstdlib>
#include <ctime>

Box::Box() {
    shapes = new ShapeList();
}

Box::~Box() {
    delete shapes;
}

void Box::addShape(Shape* shape) {
    shapes->addShape(shape);
}

void Box::removeShape(int index) {
    shapes->removeShape(index);
}

int Box::getShapeCount() const {
    return shapes->getCount();
}

ShapeList* Box::getShapes() {
    return shapes;
}

void Box::generateRandomShapes(int count) {
    // Farklı karakterler dizisi (daha çeşitli)
    char charOptions[] = {'+', '*', '-', '#', '@', 'o', '=', '~', '.', '^'};
    int charCount = 10;
    
    for (int i = 0; i < count; i++) {
        int type = rand() % 3;  // 0: Triangle, 1: Rectangle, 2: Star
        
        // Boyut (3-10 arası)
        int size = 3 + rand() % 8;
        
        // X koordinatı (sağ tarafta, sınır içinde)
        // Sol tarafta 10 birim kutu listesi var
        int minX = 12;  // Kutu listesinden sonra
        int maxX = 75 - (size * 2);  // Sağ sınırdan uzak tut
        if (maxX < minX) maxX = minX + 10;
        int x = minX + rand() % (maxX - minX + 1);
        
        // Y koordinatı (üst-alt sınır içinde)
        int minY = 1;
        int maxY = 23 - size;  // Alt kontrolden uzak tut
        if (maxY < minY) maxY = minY + 5;
        int y = minY + rand() % (maxY - minY + 1);
        
        // Rastgele karakter seç
        char drawChar = charOptions[rand() % charCount];
        
        // Rastgele z-index (0-99 arası)
        int z = rand() % 100;
        
        // POLİMORFİZM - Shape pointer'ı farklı türlere işaret ediyor
        Shape* shape = nullptr;
        switch(type) {
            case 0:
                shape = new Triangle(x, y, size, drawChar, z);
                break;
            case 1:
                shape = new Rectangle(x, y, size, drawChar, z);
                break;
            case 2:
                shape = new Star(x, y, size, drawChar, z);
                break;
        }
        
        if (shape) {
            addShape(shape);
        }
    }
}
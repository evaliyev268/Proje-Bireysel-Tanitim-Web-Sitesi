#include "FileManager.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

FileManager::FileManager(const string& file) : filename(file) {}

bool FileManager::fileExists() {
    // data.txt ana dizinde (Makefile'ın yanında)
    ifstream file("../data.txt");
    bool exists = file.good();
    file.close();
    return exists;
}

void FileManager::saveToFile(BoxList* boxes) {
    // data.txt ana dizinde
    ofstream file("../data.txt");
    
    if (!file.is_open()) return;
    
    file << boxes->getCount() << endl;
    
    BoxNode* boxNode = boxes->getHead();
    while (boxNode) {
        Box* box = boxNode->box;
        file << box->getShapeCount() << endl;
        
        ShapeNode* shapeNode = box->getShapes()->getHead();
        while (shapeNode) {
            Shape* shape = shapeNode->shape;
            
            file << shape->getTypeId() << " "
                 << shape->getX() << " "
                 << shape->getY() << " "
                 << shape->getSize() << " "
                 << shape->getDrawChar() << " "
                 << shape->getZ() << endl;
            
            shapeNode = shapeNode->next;
        }
        
        boxNode = boxNode->next;
    }
    
    file.close();
}

bool FileManager::loadFromFile(BoxList* boxes) {
    // data.txt ana dizinde
    ifstream file("../data.txt");
    
    if (!file.is_open()) {
        return false;  // Dosya açılamadı
    }
    
    // Dosya boş mu kontrol et
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    if (fileSize == 0) {
        file.close();
        return false;  // Dosya boş
    }
    file.seekg(0, ios::beg);  // Başa dön
    
    boxes->clear();
    
    int boxCount;
    
    // Geçersiz karakter kontrolü
    if (!(file >> boxCount)) {
        file.close();
        return false;  // Geçersiz format (sayı değil)
    }
    
    // Mantıksız değer kontrolü
    if (boxCount < 0 || boxCount > 10000) {
        file.close();
        return false;  // Mantıksız kutu sayısı
    }
    
    // Dosya okuma döngüsü
    for (int i = 0; i < boxCount; i++) {
        int shapeCount;
        
        if (!(file >> shapeCount)) {
            // Okuma hatası
            boxes->clear();
            file.close();
            return false;
        }
        
        if (shapeCount < 0 || shapeCount > 1000) {
            // Mantıksız şekil sayısı
            boxes->clear();
            file.close();
            return false;
        }
        
        Box* box = new Box();
        
        for (int j = 0; j < shapeCount; j++) {
            int typeId, x, y, size, z;
            char drawChar;
            
            if (!(file >> typeId >> x >> y >> size >> drawChar >> z)) {
                // Okuma hatası
                delete box;
                boxes->clear();
                file.close();
                return false;
            }
            
            // Değer kontrolü
            if (typeId < 0 || typeId > 2 ||
                x < 0 || x >= 80 ||
                y < 0 || y >= 25 ||
                size < 1 || size > 20 ||
                z < 0 || z > 99) {
                // Geçersiz değerler
                delete box;
                boxes->clear();
                file.close();
                return false;
            }
            
            Shape* shape = nullptr;
            switch(typeId) {
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
                box->addShape(shape);
            }
        }
        
        boxes->addBox(box);
    }
    
    file.close();
    return true;  // Başarılı
}

void FileManager::generateDefaultFile(BoxList* boxes) {
    srand(time(0));
    boxes->generateRandomBoxes(20);
    saveToFile(boxes);
}
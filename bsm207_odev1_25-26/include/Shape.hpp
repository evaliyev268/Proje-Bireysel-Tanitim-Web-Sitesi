#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
using namespace std;

// SOYUT TEMEL SINIF - Abstract Base Class
class Shape {
protected:
    int x, y;           // Koordinatlar
    int size;           // Boyut
    char drawChar;      // Çizim karakteri
    int z;              // Z-index (çizim önceliği)
    
public:
    // Constructor
    Shape(int xPos, int yPos, int s, char c, int zIndex);
    
    // Virtual Destructor (polimorfizm için gerekli)
    virtual ~Shape();
    
    // Saf sanal fonksiyon - her alt sınıf kendi versiyonunu yazmalı
    virtual void draw(char screen[25][80]) = 0;
    
    // Sanal fonksiyon - override edilebilir
    virtual string getTypeName() const = 0;
    
    // Getter/Setter metodları
    int getX() const;
    int getY() const;
    int getSize() const;
    char getDrawChar() const;
    int getZ() const;
    
    void setX(int xPos);
    void setY(int yPos);
    void move(int dx, int dy);
    
    // Serialization (dosyaya kaydetmek için)
    virtual int getTypeId() const = 0;
};

#endif
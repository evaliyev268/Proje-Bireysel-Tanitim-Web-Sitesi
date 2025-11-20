#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(int xPos, int yPos, int s, char c, int zIndex);
    ~Rectangle() override;
    
    // Override edilen fonksiyonlar
    void draw(char screen[25][80]) override;
    string getTypeName() const override;
    int getTypeId() const override;
};

#endif
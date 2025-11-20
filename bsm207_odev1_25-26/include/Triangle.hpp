#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
public:
    Triangle(int xPos, int yPos, int s, char c, int zIndex);
    ~Triangle() override;
    
    // Override edilen fonksiyonlar
    void draw(char screen[25][80]) override;
    string getTypeName() const override;
    int getTypeId() const override;
};

#endif
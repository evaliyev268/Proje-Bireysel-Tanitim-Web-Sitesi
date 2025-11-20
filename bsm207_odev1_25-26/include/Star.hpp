#ifndef STAR_HPP
#define STAR_HPP

#include "Shape.hpp"

class Star : public Shape {
public:
    Star(int xPos, int yPos, int s, char c, int zIndex);
    ~Star() override;
    
    // Override edilen fonksiyonlar
    void draw(char screen[25][80]) override;
    string getTypeName() const override;
    int getTypeId() const override;
};

#endif
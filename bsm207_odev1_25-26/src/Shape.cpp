#include "Shape.hpp"

Shape::Shape(int xPos, int yPos, int s, char c, int zIndex)
    : x(xPos), y(yPos), size(s), drawChar(c), z(zIndex) {}

Shape::~Shape() {
    // Virtual destructor implementation
}

int Shape::getX() const { return x; }
int Shape::getY() const { return y; }
int Shape::getSize() const { return size; }
char Shape::getDrawChar() const { return drawChar; }
int Shape::getZ() const { return z; }

void Shape::setX(int xPos) { x = xPos; }
void Shape::setY(int yPos) { y = yPos; }

void Shape::move(int dx, int dy) {
    x += dx;
    y += dy;
}
#ifndef BOX_HPP
#define BOX_HPP

#include "ShapeList.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"

// Kutu yapısı
class Box {
private:
    ShapeList* shapes;
    
public:
    Box();
    ~Box();
    
    void addShape(Shape* shape);
    void removeShape(int index);
    int getShapeCount() const;
    ShapeList* getShapes();
    
    // Rastgele şekiller oluştur
    void generateRandomShapes(int count);
};

#endif
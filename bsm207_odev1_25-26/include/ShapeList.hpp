#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP

#include "Shape.hpp"

// Tek yönlü bağlı liste düğümü
struct ShapeNode {
    Shape* shape;  // Polimorfizm - Shape pointer'ı Triangle, Rectangle veya Star'a işaret edebilir
    ShapeNode* next;
    
    ShapeNode(Shape* s) : shape(s), next(nullptr) {}
};

// Tek yönlü bağlı liste (Şekiller için)
class ShapeList {
private:
    ShapeNode* head;
    int count;
    
public:
    ShapeList();
    ~ShapeList();
    
    void addShape(Shape* shape);
    void removeShape(int index);
    Shape* getShape(int index);
    int getCount() const;
    ShapeNode* getHead() const;
    void clear();
    
    // Şekil hareket ettirme
    void moveShape(int index, int dx, int dy);
};

#endif
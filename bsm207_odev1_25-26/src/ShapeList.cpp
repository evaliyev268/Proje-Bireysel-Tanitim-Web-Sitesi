#include "ShapeList.hpp"

ShapeList::ShapeList() : head(nullptr), count(0) {}

ShapeList::~ShapeList() {
    clear();
}

void ShapeList::addShape(Shape* shape) {
    ShapeNode* newNode = new ShapeNode(shape);
    
    if (!head) {
        head = newNode;
    } else {
        ShapeNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    count++;
}

void ShapeList::removeShape(int index) {
    if (index < 0 || index >= count || !head) return;
    
    if (index == 0) {
        ShapeNode* temp = head;
        head = head->next;
        delete temp->shape;
        delete temp;
    } else {
        ShapeNode* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        ShapeNode* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete->shape;
        delete toDelete;
    }
    count--;
}

Shape* ShapeList::getShape(int index) {
    if (index < 0 || index >= count) return nullptr;
    
    ShapeNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->shape;
}

int ShapeList::getCount() const {
    return count;
}

ShapeNode* ShapeList::getHead() const {
    return head;
}

void ShapeList::clear() {
    while (head) {
        ShapeNode* temp = head;
        head = head->next;
        delete temp->shape;
        delete temp;
    }
    count = 0;
}

void ShapeList::moveShape(int index, int dx, int dy) {
    Shape* shape = getShape(index);
    if (shape) {
        shape->move(dx, dy);  // Polimorfizm kullanıldı
    }
}
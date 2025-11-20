#include "BoxList.hpp"
#include <cstdlib>

BoxList::BoxList() : head(nullptr), tail(nullptr), count(0) {}

BoxList::~BoxList() {
    clear();
}

void BoxList::addBox(Box* box) {
    BoxNode* newNode = new BoxNode(box);
    
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

void BoxList::removeBox(int index) {
    if (index < 0 || index >= count || !head) return;
    
    BoxNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }
    
    delete current->box;
    delete current;
    count--;
}

Box* BoxList::getBox(int index) {
    if (index < 0 || index >= count) return nullptr;
    
    BoxNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->box;
}

int BoxList::getCount() const {
    return count;
}

BoxNode* BoxList::getHead() const {
    return head;
}

void BoxList::clear() {
    while (head) {
        BoxNode* temp = head;
        head = head->next;
        delete temp->box;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

void BoxList::generateRandomBoxes(int boxCount) {
    // Tam 20 kutu oluştur
    for (int i = 0; i < 20; i++) {
        Box* box = new Box();
        
        // Her kutu 2-7 arası şekil içerecek
        int shapeCount = 2 + rand() % 6;  // 2-7 arası
        box->generateRandomShapes(shapeCount);
        
        addBox(box);
    }
}
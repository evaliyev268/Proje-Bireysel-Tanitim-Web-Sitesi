#ifndef BOXLIST_HPP
#define BOXLIST_HPP

#include "Box.hpp"

// İki yönlü bağlı liste düğümü
struct BoxNode {
    Box* box;
    BoxNode* next;
    BoxNode* prev;
    
    BoxNode(Box* b) : box(b), next(nullptr), prev(nullptr) {}
};

// İki yönlü bağlı liste (Kutular için)
class BoxList {
private:
    BoxNode* head;
    BoxNode* tail;
    int count;
    
public:
    BoxList();
    ~BoxList();
    
    void addBox(Box* box);
    void removeBox(int index);
    Box* getBox(int index);
    int getCount() const;
    BoxNode* getHead() const;
    void clear();
    
    // Rastgele kutular oluştur
    void generateRandomBoxes(int boxCount);
};

#endif
#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include "BoxList.hpp"
#include <string>

using namespace std;

class FileManager {
private:
    string filename;
    
public:
    FileManager(const string& file);
    
    bool fileExists();
    void saveToFile(BoxList* boxes);
    bool loadFromFile(BoxList* boxes);  // ✅ Artık bool döndürüyor
    void generateDefaultFile(BoxList* boxes);
};

#endif
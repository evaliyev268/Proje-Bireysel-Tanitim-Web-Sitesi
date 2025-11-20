// ÖNCELİKLE TÜM C++ STANDART KÜTÜPHANELERİNİ INCLUDE ET
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// SONRA kendi header'larını include et
#include "BoxList.hpp"
#include "FileManager.hpp"
#include "MenuManager.hpp"

// EN SON Windows.h içeren header'ları include et
#include "Renderer.hpp"
#include "InputHandler.hpp"

using namespace std;

// Forward declaration
bool runMainProgram(BoxList* boxes, Renderer* renderer, FileManager* fileManager);

int main() {
    srand(time(0));
    
    // Konsol boyutunu ayarla
    system("mode con: cols=80 lines=25");
    
    bool programRunning = true;
    
    while (programRunning) {
        // Başlangıç ekranını göster
        MenuManager::showWelcomeScreen();
        int choice = MenuManager::getUserChoice();
        
        if (choice == 3) {
            MenuManager::clearConsole();
            cout << "\n\n  Program kapatiliyor... Gorusuruz!\n\n";
            Sleep(1000);
            break;
        }
        
        // Nesneleri oluştur
        BoxList* boxes = new BoxList();
        FileManager* fileManager = new FileManager("data.txt");
        
        if (choice == 1) {
            // DOSYADAN OKU
            MenuManager::showLoadingMessage("Dosya okunuyor");
            
            if (fileManager->fileExists()) {
                fileManager->loadFromFile(boxes);
                
                if (boxes->getCount() == 0) {
                    MenuManager::clearConsole();
                    cout << "\n  UYARI: Dosya bos veya gecersiz!\n";
                    cout << "  Rastgele veri olusturuluyor";
                    for (int i = 0; i < 3; i++) {
                        Sleep(300);
                        cout << ".";
                        cout.flush();
                    }
                    cout << "\n";
                    
                    boxes->generateRandomBoxes(20);
                    fileManager->saveToFile(boxes);
                    MenuManager::showLoadingMessage("  Dosyaya kaydediliyor");
                }
            } else {
                MenuManager::clearConsole();
                cout << "\n  UYARI: data.txt bulunamadi!\n";
                cout << "  Rastgele veri olusturuluyor";
                for (int i = 0; i < 3; i++) {
                    Sleep(300);
                    cout << ".";
                    cout.flush();
                }
                cout << "\n";
                
                boxes->generateRandomBoxes(20);
                fileManager->saveToFile(boxes);
                MenuManager::showLoadingMessage("  Dosyaya kaydediliyor");
            }
        } else if (choice == 2) {
            // RASTGELE OLUŞTUR
            MenuManager::showLoadingMessage("Rastgele kutular olusturuluyor");
            boxes->generateRandomBoxes(20);
            fileManager->saveToFile(boxes);
            MenuManager::showLoadingMessage("Dosyaya kaydediliyor");
        }
        
        // EKRANI TEMİZLE VE RENDERER OLUŞTUR
        Sleep(500);
        system("cls");
        
        Renderer* renderer = new Renderer();
        
        // Ana programı çalıştır
        bool returnToMenu = runMainProgram(boxes, renderer, fileManager);
        
        // Belleği temizle
        delete boxes;
        delete renderer;
        delete fileManager;
        
        if (!returnToMenu) {
            programRunning = false;
        }
    }
    
    return 0;
}

bool runMainProgram(BoxList* boxes, Renderer* renderer, FileManager* fileManager) {
    // Durum değişkenleri
    const int BOXES_PER_PAGE = 7;  // Her sayfada 7 kutu
    
    int selectedBoxIndex = 0;
    int selectedShapeIndex = 0;
    int scrollOffset = 0;  // Sayfanın başlangıç index'i
    bool insideBox = false;
    bool running = true;
    
    // İlk render
    renderer->render(boxes, selectedBoxIndex, selectedShapeIndex, insideBox, scrollOffset);
    
    while (running) {
        Sleep(50);
        
        bool needsRedraw = false;
        
        // TÜM KUTULAR SİLİNDİYSE BAŞLANGIÇ EKRANINA DÖN
        if (boxes->getCount() == 0) {
            system("cls");
            cout << "\n\n  ========================================\n";
            cout << "  ||  TUM KUTULAR SILINDI!              ||\n";
            cout << "  ========================================\n\n";
            cout << "  Baslangic ekranina donuluyor";
            for (int i = 0; i < 3; i++) {
                Sleep(400);
                cout << ".";
                cout.flush();
            }
            cout << "\n\n";
            Sleep(1000);
            return true;
        }
        
        if (!insideBox) {
            // ====== KUTU LİSTESİ MODUNDA ======
            
            if (InputHandler::isKeyPressed('W')) {
                if (selectedBoxIndex > 0) {
                    selectedBoxIndex--;
                    
                    // Eğer seçili index mevcut sayfanın dışına çıktıysa, önceki sayfaya geç
                    if (selectedBoxIndex < scrollOffset) {
                        scrollOffset = (selectedBoxIndex / BOXES_PER_PAGE) * BOXES_PER_PAGE;
                    }
                    
                    needsRedraw = true;
                }
                InputHandler::waitForKeyRelease('W');
            }
            
            if (InputHandler::isKeyPressed('S')) {
                if (selectedBoxIndex < boxes->getCount() - 1) {
                    selectedBoxIndex++;
                    
                    // Eğer seçili index mevcut sayfanın dışına çıktıysa, sonraki sayfaya geç
                    if (selectedBoxIndex >= scrollOffset + BOXES_PER_PAGE) {
                        scrollOffset = (selectedBoxIndex / BOXES_PER_PAGE) * BOXES_PER_PAGE;
                    }
                    
                    needsRedraw = true;
                }
                InputHandler::waitForKeyRelease('S');
            }
            
            if (InputHandler::isKeyPressed('F')) {
                Box* currentBox = boxes->getBox(selectedBoxIndex);
                if (currentBox && currentBox->getShapeCount() > 0) {
                    insideBox = true;
                    selectedShapeIndex = 0;
                    needsRedraw = true;
                }
                InputHandler::waitForKeyRelease('F');
            }
            
            // KUTUYU SİL (C tuşu)
            if (InputHandler::isKeyPressed('C')) {
                boxes->removeBox(selectedBoxIndex);
                
                if (boxes->getCount() > 0) {
                    // Index ayarla
                    if (selectedBoxIndex >= boxes->getCount()) {
                        selectedBoxIndex = boxes->getCount() - 1;
                    }
                    
                    // Scroll offset'i yeniden hesapla
                    scrollOffset = (selectedBoxIndex / BOXES_PER_PAGE) * BOXES_PER_PAGE;
                    
                    needsRedraw = true;
                } else {
                    running = false;
                }
                
                InputHandler::waitForKeyRelease('C');
            }
            
        } else {
            // ====== KUTU İÇİ MODUNDA ======
            
            Box* currentBox = boxes->getBox(selectedBoxIndex);
            
            if (currentBox && currentBox->getShapeCount() > 0) {
                if (InputHandler::isKeyPressed('E')) {
                    if (selectedShapeIndex < currentBox->getShapeCount() - 1) {
                        selectedShapeIndex++;
                        needsRedraw = true;
                    }
                    InputHandler::waitForKeyRelease('E');
                }
                if (InputHandler::isKeyPressed('G')) {
                    if (selectedShapeIndex > 0) {
                        selectedShapeIndex--;
                        needsRedraw = true;
                    }
                    InputHandler::waitForKeyRelease('G');
                }
                
                // Şekil hareketi
                if (InputHandler::isKeyPressed('W')) {
                    currentBox->getShapes()->moveShape(selectedShapeIndex, 0, -1);
                    needsRedraw = true;
                    InputHandler::waitForKeyRelease('W');
                }
                if (InputHandler::isKeyPressed('S')) {
                    currentBox->getShapes()->moveShape(selectedShapeIndex, 0, 1);
                    needsRedraw = true;
                    InputHandler::waitForKeyRelease('S');
                }
                if (InputHandler::isKeyPressed('A')) {
                    currentBox->getShapes()->moveShape(selectedShapeIndex, -1, 0);
                    needsRedraw = true;
                    InputHandler::waitForKeyRelease('A');
                }
                if (InputHandler::isKeyPressed('D')) {
                    currentBox->getShapes()->moveShape(selectedShapeIndex, 1, 0);
                    needsRedraw = true;
                    InputHandler::waitForKeyRelease('D');
                }
                
                // SEÇİLİ ŞEKLİ SİL (C tuşu)
                if (InputHandler::isKeyPressed('C')) {
                    currentBox->removeShape(selectedShapeIndex);
                    
                    if (currentBox->getShapeCount() == 0) {
                        insideBox = false;
                        boxes->removeBox(selectedBoxIndex);
                        
                        if (boxes->getCount() == 0) {
                            running = false;
                        } else {
                            if (selectedBoxIndex >= boxes->getCount()) {
                                selectedBoxIndex = boxes->getCount() - 1;
                            }
                            scrollOffset = (selectedBoxIndex / BOXES_PER_PAGE) * BOXES_PER_PAGE;
                        }
                    } else {
                        if (selectedShapeIndex >= currentBox->getShapeCount()) {
                            selectedShapeIndex = currentBox->getShapeCount() - 1;
                        }
                    }
                    
                    needsRedraw = true;
                    InputHandler::waitForKeyRelease('C');
                }
            } else {
                insideBox = false;
                boxes->removeBox(selectedBoxIndex);
                
                if (boxes->getCount() == 0) {
                    running = false;
                } else {
                    if (selectedBoxIndex >= boxes->getCount()) {
                        selectedBoxIndex = boxes->getCount() - 1;
                    }
                    scrollOffset = (selectedBoxIndex / BOXES_PER_PAGE) * BOXES_PER_PAGE;
                    needsRedraw = true;
                }
            }
            
            if (InputHandler::isKeyPressed(VK_ESCAPE)) {
                insideBox = false;
                needsRedraw = true;
                InputHandler::waitForKeyRelease(VK_ESCAPE);
            }
        }
        
        // Program çıkışı (Q tuşu)
        if (InputHandler::isKeyPressed('Q')) {
            fileManager->saveToFile(boxes);
            
            system("cls");
            cout << "\n\n  ========================================\n";
            cout << "  ||  VERILER KAYDEDILDI!               ||\n";
            cout << "  ========================================\n\n";
            cout << "  Baslangic ekranina donuluyor";
            for (int i = 0; i < 3; i++) {
                Sleep(400);
                cout << ".";
                cout.flush();
            }
            cout << "\n\n";
            Sleep(800);
            
            running = false;
            return true;
        }
        
        if (needsRedraw) {
            renderer->render(boxes, selectedBoxIndex, selectedShapeIndex, insideBox, scrollOffset);
        }
    }
    
    return true;
}
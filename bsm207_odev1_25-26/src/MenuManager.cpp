#include "MenuManager.hpp"
#include <iostream>
#include <conio.h>

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

using namespace std;

void MenuManager::clearConsole() {
    system("cls");
}

void MenuManager::showWelcomeScreen() {
    clearConsole();
    
    cout << "\n";
    cout << "  ========================================\n";
    cout << "  ||                                    ||\n";
    cout << "  ||                                    ||\n";
    cout << "  ||                                    ||\n";
    cout << "  ||   BSM207 - Veri Yapilari           ||\n";
    cout << "  ||   Odev 1                           ||\n";
    cout << "  ||                                    ||\n";
    cout << "  ========================================\n";
    cout << "\n\n";
    cout << "  Program nasil baslatilsin?\n\n";
    cout << "  [1] Dosyadan Oku (data.txt)\n";
    cout << "  [2] Rastgele Olustur (~20 kutu)\n";
    cout << "  [3] Cikis\n\n";
    cout << "  Seciminiz (1/2/3): ";
}

int MenuManager::getUserChoice() {
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == '1') {
                cout << "1" << endl;
                return 1;
            } else if (ch == '2') {
                cout << "2" << endl;
                return 2;
            } else if (ch == '3') {
                cout << "3" << endl;
                return 3;
            }
        }
        Sleep(50);
    }
}

void MenuManager::showLoadingMessage(const string& message) {
    cout << "\n  " << message;
    for (int i = 0; i < 3; i++) {
        Sleep(300);
        cout << ".";
        cout.flush();
    }
    cout << " TAMAM!\n";
    Sleep(800);
}
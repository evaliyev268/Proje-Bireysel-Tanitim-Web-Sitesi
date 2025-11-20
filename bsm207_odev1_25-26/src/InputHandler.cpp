#include "InputHandler.hpp"
#include <conio.h>

bool InputHandler::isKeyPressed(int vKey) {
    return GetAsyncKeyState(vKey) & 0x8000;
}

char InputHandler::getLastKey() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}

void InputHandler::waitForKeyRelease(int vKey) {
    while (GetAsyncKeyState(vKey) & 0x8000) {
        Sleep(10);
    }
}
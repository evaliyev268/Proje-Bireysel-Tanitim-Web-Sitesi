#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

class InputHandler {
public:
    static bool isKeyPressed(int vKey);
    static char getLastKey();
    static void waitForKeyRelease(int vKey);
};

#endif
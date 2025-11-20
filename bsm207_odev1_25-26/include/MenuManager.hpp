#ifndef MENUMANAGER_HPP
#define MENUMANAGER_HPP

#include <string>
using namespace std;

class MenuManager {
public:
    static void showWelcomeScreen();
    static int getUserChoice();
    static void clearConsole();
    static void showLoadingMessage(const string& message);
};

#endif
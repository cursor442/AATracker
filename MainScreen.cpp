// Draw the main screen of the application

#include "AA_Tracker.h"

bool Game::MainScreen(HDC& hdc, PAINTSTRUCT& ps, Board& gameBoard)
{
    hideScreen();

    TCHAR greeting[] = _T("Hello, Windows desktop!");

    TextOut(hdc,
        25, 25,
        greeting, _tcslen(greeting));

    return true;
}
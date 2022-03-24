#include <iostream>
#include <vector>
#include "scene_utils.h"
#include "display_tools.h"
#include "debug.h"
#include <windows.h>
#include "tsv_parser.h"
#include "game.h"

using namespace scene_utils;

int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    RECT ConstConsoleRect;
    GetWindowRect(console, &ConstConsoleRect);

    MoveWindow( console, ConsoleRect.left, ConsoleRect.top, 1024, 720, TRUE );

    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    ScrollWindow(console,10,250,0,&ConstConsoleRect);

    debug::Debugger::set_on_off(true);

    game::GameSettings* GameSettings = new game::GameSettings("test.tsv", false, false, true, 80);

    game::GameState* GameState = new game::GameState(GameSettings);
    GameState->start_game();
    return 0;
}

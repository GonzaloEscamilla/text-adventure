#include <iostream>
#include <vector>
#include "scene_utils.h"
#include "display_tools.h"
#include "debug.h"
//#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "tsv_parser.h"

using namespace scene_utils;


//std::vector<Scene> game_scenes;
std::map<std::string, Scene*> game_scenes_map;

Scene* current_scene;
bool is_playing;

std::string file_name = "test.tsv";


void go_to_next_scene(int option_selected) //TODO: Maybe not the current name.
{
    switch (option_selected)
    {
    case 1:
        current_scene = game_scenes_map[current_scene->get_scene_options()[0]->get_next_scene_id()];
        break;
    case 2:
        current_scene = game_scenes_map[current_scene->get_scene_options()[1]->get_next_scene_id()];
        break;
    default:
        break;
    }
}

void set_starting_scene()
{
    //current_scene = &game_scenes[0];
    debug::Debugger::log("Set Starting Scene...");
    current_scene = game_scenes_map["scene_0"]; 
    debug::Debugger::log("Done...");
    debug::Debugger::log("Testing First Scene Options");
    debug::Debugger::log("Description A : " + current_scene->get_scene_options()[0]->get_description());
    debug::Debugger::log("Next Scene A : " + current_scene->get_scene_options()[0]->get_next_scene_id());

}

void init_scenes()
{
    scene_utils::ScenesBuilder scenes_builder(file_name);
    //game_scenes = scenes_builder.get_game_scenes();
    scenes_builder.get_game_scenes_map(game_scenes_map);

    debug::Debugger::log("After initializaing map");
    debug::Debugger::log("Scene 1:");
    debug::Debugger::log(game_scenes_map["scene_0"]->get_title());
}

void display_current_scene()
{
    TUI::display_scene(*current_scene);
}

std::string get_user_input()
{
    std::cout << ">";
    std::string input_value;
    std::cin >> input_value;
    //system("cls");
    return input_value;
}

void handle_user_input(std::string user_input)
{
    if (user_input == "1")
    {
        debug::Debugger::log("Option A selected");
        go_to_next_scene(1);
    }
    if (user_input == "2")
    {
        debug::Debugger::log("Option B selected");
        go_to_next_scene(2);
    }
}

void game_loop()
{
    while (is_playing)
    {
        display_current_scene();
        handle_user_input(get_user_input());
    }
}

void start_game()
{
    //TODO: Here this might present you the first room, the title of the game, and the initial stuff
    is_playing = true;

    init_scenes();
    set_starting_scene();
    game_loop();
}

int main()
{

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow( console, ConsoleRect.left, ConsoleRect.top, 1024, 720, TRUE );

    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    debug::Debugger::set_on_off(false);

    start_game();
    return 0;
}

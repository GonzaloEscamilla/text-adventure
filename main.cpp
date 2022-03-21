#include <iostream>
#include <vector>
#include "scene_utils.h"
#include "display_tools.h"

//#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "tsv_parser.h"

using namespace scene_utils;


std::vector<Scene> game_scenes;
Scene* current_scene;
bool is_playing;

std::string file_name = "test.tsv";

void go_to_next_scene(int option_selected) //TODO: Maybe not the current name.
{
    switch (option_selected)
    {
    case 1:
        std::cout << "Current Scene Id: " << current_scene->get_id() << std::endl; 
        std::cout << "Current Scene OptionA next: " << current_scene->get_scene_options()[0].next_scene_id << std::endl; 
        std::cout << "Current Scene OptionA scene pointer: " << current_scene->get_scene_options()[0].next_scene->get_id() << std::endl; 
        current_scene = current_scene->get_scene_options()[0].next_scene;
        break;
    case 2:
        current_scene = current_scene->get_scene_options()[1].next_scene;
        break;
    default:
        break;
    }
}

void set_starting_scene()
{
    current_scene = &game_scenes[0];
}

void init_scenes()
{
    scene_utils::ScenesBuilder scenes_builder(file_name);
    game_scenes = scenes_builder.get_game_scenes();
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
        //std::cout << "Option A" << std::endl;
        go_to_next_scene(1);
    }
    if (user_input == "2")
    {
        //std::cout << "Option B" << std::endl;
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


  
    start_game();
    return 0;
}

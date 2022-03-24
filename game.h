#ifndef _GAME_
#define _GAME_

#include <iostream>
#include <map>
#include <vector>
#include "scene_utils.h"
#include "display_tools.h"
#include "debug.h"
#include <windows.h>
#include "tsv_parser.h"

using namespace scene_utils;

namespace game
{
    class GameState
    {
    public:
        GameState();
        void start_game(std::string source_file_name);

    private:
        void init_scenes(std::string source_file_name);
        void set_starting_scene();
        void game_loop();
        void set_next_scene(int option_selected);
        void display_current_scene();
        void handle_user_input(std::string user_input);
        std::string get_user_input();

        std::map<std::string, Scene*> game_scenes_map;
        Scene* current_scene;
        bool is_playing = false;
    };
} 


#endif
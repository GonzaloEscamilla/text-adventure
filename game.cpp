#include "game.h"

using namespace scene_utils;

namespace game
{
    GameState::GameState()
    {
        //start_game("test.tsv");
    }

    void GameState::start_game(std::string source_file_name)
    {
        debug::Debugger::log("Start Game");

        this->is_playing = true; // Ask a dev what is the diferentece between this and without the hits in the context of the class.

        init_scenes(source_file_name);
        set_starting_scene();
        game_loop();
    }
    void GameState::init_scenes(std::string source_file_name)
    {
        scene_utils::ScenesBuilder scenes_builder(source_file_name);
        scenes_builder.get_game_scenes_map(game_scenes_map);

        debug::Debugger::log("First Scene: " + game_scenes_map["scene_0"]->get_title());
    }
    void GameState::set_starting_scene()
    {
        debug::Debugger::log("Set Starting Scene...");
        
        this->current_scene = game_scenes_map["scene_0"]; 

        debug::Debugger::log("Done...");
    }
    void GameState::game_loop()
    {
        while (is_playing) // TODO: Whe need an exit condition.
        {
            display_current_scene();
            handle_user_input(get_user_input());
        }
    }

    void GameState::display_current_scene()
    {
        TUI::display_scene(*current_scene);
    }

    std::string GameState::get_user_input()
    {
        std::cout << ">";
        std::string input_value;
        std::cin >> input_value;
        //system("cls");
        return input_value;
    }

    void GameState::handle_user_input(std::string user_input)
    {
        if (user_input == "1")
        {
            debug::Debugger::log("Option A selected");
            set_next_scene(1);
        }
        if (user_input == "2")
        {
            debug::Debugger::log("Option B selected");
            set_next_scene(2);
        }
    }
    void GameState::set_next_scene(int option_selected) //TODO: Maybe not the current name.
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
} 



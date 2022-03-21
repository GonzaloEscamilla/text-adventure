
#ifndef _SCENE_UTILS_
#define _SCENE_UTILS_

#include <iostream>
#include <string>
#include <vector>
#include "tsv_parser.h"



namespace scene_utils
{
    struct SceneOption
    {   
        std::string description;
        std::string next_scene_id;
        class Scene* next_scene;
    };

    class Scene
    {
        public:
            Scene(std::string id, std::string title, std::string description, std::string call_to_action, std::vector<SceneOption> scene_options);
            std::string get_id() const;
            std::string get_title() const;
            std::string get_description() const;
            std::string get_call_to_action() const;
            std::vector<SceneOption> get_scene_options();

        private:
            std::string id;
            std::string title;
            std::string description;
            std::string call_to_action;
            std::vector<SceneOption> scene_options;
    };

    
    class ScenesBuilder
    {
        public:
            ScenesBuilder(std::string file_name);
            std::vector<Scene> get_game_scenes();
        private:
            std::vector<Scene> game_scenes;
            std::vector<std::string> file_elements;
            std::string file_name;
    };
}

#endif
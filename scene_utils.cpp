#include "scene_utils.h"

namespace scene_utils
{

    ScenesBuilder::ScenesBuilder(std::string file_name)
    {
        this->file_name = file_name;
    }

    void ScenesBuilder::get_game_scenes_map(std::map<std::string, Scene*>& scenes_map)
    {
        file_elements = serialization_tools::get_file_elements(file_name, 8);
        int rows_amount = file_elements.size()/8;
        
        if(rows_amount%2 != 0)
            debug::Debugger::log("There is an error with the file. Please check that every column is filled!");
    
        int columns_amount = 8;
        for (int rows = 1; rows < rows_amount; rows++)
        {
            int current_index = columns_amount * rows;
            
            std::vector<SceneOption*> scene_options;

            scene_options.push_back(new SceneOption(file_elements[current_index + 4 ], file_elements[current_index + 5 ]));
            scene_options.push_back(new SceneOption(file_elements[current_index + 6 ], file_elements[current_index + 7 ]));


            game_scenes.push_back(new Scene(file_elements[current_index],
                                        file_elements[current_index + 1],
                                        file_elements[current_index + 2],
                                        file_elements[current_index + 3],
                                        scene_options));
        }

        debug::Debugger::log("Amounts of scenes: " + game_scenes.size());

        for (int i = 0; i < game_scenes.size(); i++)
            scenes_map[game_scenes[i]->get_id()] = game_scenes[i];
    }

    Scene::Scene(std::string id, std::string title, std::string description, std::string call_to_action, std::vector<SceneOption*> scene_options)
    {
        this->id = id;
        this->scene_options = scene_options;
        this->title = title;
        this->description = description;
        this->call_to_action = call_to_action;
    }

    std::string Scene::get_id() const
    {
        return id;
    }

    std::string Scene::get_title() const
    {
        return title;
    }

    std::string Scene::get_description() const
    {
        return description;
    }

    std::string Scene::get_call_to_action() const
    {
        return call_to_action;
    }

    std::vector<SceneOption*> Scene::get_scene_options()
    {
        return scene_options;
    }
    
    SceneOption::SceneOption(std::string description, std::string next_scene_id)
    {
        this->description = description;
        this->next_scene_id = next_scene_id;
    }

    std::string SceneOption::get_description()
    {
        return this->description;
    }

    std::string SceneOption::get_next_scene_id()
    {
        return this->next_scene_id;
    }
    
}

#include "scene_utils.h"


namespace scene_utils
{
    Scene::Scene(std::string id, std::string title, std::string description, std::string call_to_action, std::vector<SceneOption> scene_options)
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
    std::vector<SceneOption> Scene::get_scene_options()
    {
        return scene_options;
    }

    ScenesBuilder::ScenesBuilder(std::string file_name)
    {
        this->file_name = file_name;
    }
    std::vector<Scene> ScenesBuilder::get_game_scenes()
    {
        file_elements = serialization_tools::get_file_elements(file_name, 8);
        int rows_amount = file_elements.size()/8;
        
        if(rows_amount%2 != 0)
            std::cout << "There is an error with the file. Please check that every column is filled!" << std::endl;
    

        std::cout << "row amoujnt: " << rows_amount << std::endl;

        int columns_amount = 8;
        for (int rows = 1; rows < rows_amount; rows++)
        {
            int current_index = columns_amount * rows;
            
            std::vector<SceneOption> scene_options;
            scene_options.push_back({file_elements[current_index + 4 ], file_elements[current_index + 5 ], NULL });
            scene_options.push_back({file_elements[current_index + 6 ], file_elements[current_index + 7 ], NULL });


            game_scenes.push_back(Scene(file_elements[current_index],
                                        file_elements[current_index + 1],
                                        file_elements[current_index + 2],
                                        file_elements[current_index + 3],
                                        scene_options));
        }

        for (int i = 0; i < game_scenes.size(); i++)
        {

            std::string id_to_find_option_a = game_scenes[i].get_scene_options()[0].next_scene_id;
            std::string id_to_find_option_b = game_scenes[i].get_scene_options()[1].next_scene_id;
            
            std::cout << "Game Scenes Size: " << game_scenes.size() << std::endl;
            std::cout << "Id to find A: "  << id_to_find_option_a << std::endl;
            std::cout << "Id to find B: "  << id_to_find_option_b << std::endl;

            for (int j = 0; j < game_scenes.size(); j++)
            {
                if (game_scenes[j].get_id() == id_to_find_option_a)
                {
                    //  std::cout << "Enter A" << " The scene is: " << &game_scenes[j].get_id() << std::endl;
                    //std::cout << "here the pointer is: " << game_scenes[j].get_id() << std::endl;
                    //std::cout << "The new value: " << game_scenes[i].get_scene_options()[0].next_scene << std::endl;

                    /*
                    game_scenes[i].get_scene_options()[0].next_scene = &game_scenes[j];
                    std::cout << "The new value: " << game_scenes[i].get_scene_options()[0].next_scene->get_title() << std::endl;
                */
                }
                if (game_scenes[j].get_id() == id_to_find_option_b)
                {
                    // std::cout << "Enter B" << " The scene is: " << &game_scenes[j].get_id() << std::endl;
                  //  std::cout << "here the pointer is: " << game_scenes[j].get_id() << std::endl;
                   // std::cout << "The new value: " << game_scenes[i].get_scene_options()[1].next_scene << std::endl;

                    /*
                    game_scenes[i].get_scene_options()[1].next_scene = &game_scenes[j];
                */
                }
            }
        }

        return game_scenes;
    }

}

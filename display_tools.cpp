#include <iostream>
#include <string>
#include <vector>
#include <math.h> 

#include "display_tools.h"
#include "scene_utils.h"

namespace TUI
{
    UiFrame::UiFrame(std::string frame)
    {
        this->frame = frame;
    }

    std::string UiFrame::get_frame() const
    {
        return UiFrame::frame;
    }

    std::string build_title_header()
    {
        std::string frame = "";
        frame.append(  "\n")  
             .append(  "              -opdbqpdbqpdbqpdbqpdbqpdbqpdbqpdbq|   Nivelheim   |dbqpdbqpdbqpdbqpdbqpdbqpdbqpdbqpo-                      \n");  
        return frame;
    }

    void display_scene(scene_utils::Scene scene_to_display)
    {
        std::cout << scene_to_display.get_title() << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << std::endl;

        std::cout << scene_to_display.get_description() << std::endl;
        std::cout << std::endl;

        std::cout << scene_to_display.get_call_to_action() << std::endl;

        std::cout << std::endl;

        for (int i = 0; i < scene_to_display.get_scene_options().size(); i++)
        {
            std::cout << scene_to_display.get_scene_options()[i].get_description() << std::endl;
        }
        
        std::cout << std::endl;
    }

    void test_insert_title_in_header()
    {
        std::string screen_width_line = "";
        std::string title_to_insert = "The passages of the nifelheim";
        
        int is_pair = title_to_insert.size() % 2;
        int remove_amount_left = title_to_insert.size()/2;
        int remove_amount_right = title_to_insert.size()/2;

        if (is_pair != 0)
            remove_amount_right++;

        for (int i = 0; i < 123; i++)
            screen_width_line += '+';

        int screen_midle_char_index =  screen_width_line.size()/2;
       
       
        screen_width_line.insert(screen_midle_char_index, title_to_insert);


        screen_width_line.erase(0,remove_amount_left);
        for (int i = 0; i < remove_amount_right; i++)
            screen_width_line.pop_back();
        

        std::cout << screen_width_line << std::endl;
    }


}


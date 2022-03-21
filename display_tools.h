#ifndef _TUI_
#define _TUI_

#include<string>
#include<iostream>
#include "scene_utils.h"


namespace TUI
{
    class UiFrame
    {
        std::string frame;
        public:
            UiFrame(std::string frame);
            std::string get_frame() const;
    };

    std::string build_title_header();
    void display_scene(scene_utils::Scene scene_to_display);
}

#endif

#ifndef _GAME_SETTINGS_
#define _GAME_SETTINGS_

#include <string>
namespace game
{
    class GameSettings
    {
    public:
        GameSettings(std::string scenes_source_file_name, bool is_debugger_active, bool refresh_console = false);
        std::string get_source_file_name();
        bool get_is_debugger_active();
        bool get_refresh_console();
    private:
        std::string scenes_source_file_name = "";
        bool is_debugger_active = false;
        bool refresh_console = false;
    };
}


#endif
#ifndef _GAME_SETTINGS_
#define _GAME_SETTINGS_

#include <string>
namespace game
{
    class GameSettings
    {
    public:
        GameSettings(std::string scenes_source_file_name, bool is_debugger_active,  bool refresh_console, bool format_text, int amount_chars_per_line);
        std::string get_source_file_name();
        bool get_is_debugger_active();
        bool get_refresh_console();
        bool get_format_text();
        int get_amount_chars_per_line();
    private:
        std::string scenes_source_file_name = "";
        bool is_debugger_active = false;
        bool refresh_console = false;
        bool format_text = true;
        int amount_chars_per_line;
    };
}


#endif

#include "game_settings.h"

namespace game
{
    GameSettings::GameSettings(std::string scenes_source_file_name, bool is_debugger_active,  bool refresh_console)
    {
        this->scenes_source_file_name = scenes_source_file_name;
        this->is_debugger_active = is_debugger_active;
        this->refresh_console = refresh_console;
    }

    std::string GameSettings::get_source_file_name()
    {
        return this->scenes_source_file_name;
    }
    bool GameSettings::get_is_debugger_active()
    {
        return this->is_debugger_active;
    }
    bool GameSettings::get_refresh_console()
    {
        return this->refresh_console;
    }
}

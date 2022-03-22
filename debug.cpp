#include "debug.h"

namespace debug
{
    Debugger* Debugger::ptr_instance = nullptr;

    Debugger::Debugger()
    {
        this->is_debug_mode_on = true;
    }
    void Debugger::Terminate()
    {
        delete ptr_instance;
        ptr_instance = nullptr;
    }
    void Debugger::log(std::string message)
    {
        Instance().priv_log(message);
    }
    void Debugger::priv_log(std::string message)
    {
        if (!this->is_debug_mode_on) return;

        std::cout << message << std::endl;
    }
    void Debugger::set_on_off(bool is_debug_mode_on)
    {
        Instance().priv_set_on_off(is_debug_mode_on);
    }
    void Debugger::priv_set_on_off(bool is_debug_mode_on)
    {
        this->is_debug_mode_on = is_debug_mode_on;
    }
}


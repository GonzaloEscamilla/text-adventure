#if !defined(_DEBUG_)
#define _DEBUG_

#include <iostream>

namespace debug
{
    class Debugger
    {
        private:
            static Debugger* ptr_instance;
            static Debugger& Instance()
            {
                if(!ptr_instance)
                {
                    ptr_instance = new Debugger();
                }
                return *ptr_instance;
            } 
            bool is_debug_mode_on;
            void priv_log(std::string message);
            void priv_set_on_off(bool is_debug_mode_on);
            Debugger();

        public:
            static void Terminate();
            static void log(std::string message);
            static void set_on_off(bool is_debug_mode_on);
    };
}

#endif // _DEBUG_

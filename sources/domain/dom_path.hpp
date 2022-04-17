#ifndef DOM_PATHS_HPP
#define DOM_PATHS_HPP

#include <fstream>

#include "domain/dom_flags.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"

#if     defined(BILL_WINDOWS)
    #include <windows.h>
#else   defined(LINUS_LINUX)
    #include <unistd.h>
    #include <limits.h>
#endif

#if     defined(BILL_WINDOWS)
    #define MAIN_PATH       dom::MainPath::getPath()
    #define RESOURCES       MAIN_PATH   + "resources\\"
    #define OUTPUT_PATH     RESOURCES   + "output\\"
    #define LOGS_PATH       RESOURCES   + "logs\\"
    #define ERRORS_PATH     RESOURCES   + "errors\\"
// !BILL_WINDOWS
#elif   defined(LINUS_LINUX)
    #define MAIN_PATH       dom::MainPath::getPath()
    #define RESOURCES       MAIN_PATH   + "resources/"
    #define OUTPUT_PATH     RESOURCES   + "output/"
    #define LOGS_PATH       RESOURCES   + "logs/"
    #define ERRORS_PATH     WORK_DIR    + "errors/"
// !LINUS_LINUX
#else   // NUN
    #define MAIN_PATH       ""
    #define RESOURCES       ""
    #define OUTPUT_PATH     ""
    #define LOGS_PATH       ""
    #define LOGS_PATH       ""
// !NUN
#endif

namespace dom
{
    class MainPath
    {
    public:
        static str_const_ref getPath();
    private:
        static str_val getMainPath();
    };
}




#endif // !DOM_PATHS_HPP
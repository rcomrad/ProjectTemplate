#ifndef DOM_PATHS_HPP
#define DOM_PATHS_HPP

#include "main/flags.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"

#if     defined(BILL_WINDOWS)
#include <windows.h>
#else   defined(LINUS_LINUX)
#include <unistd.h>
#include <limits.h>
#endif

#if     defined(BILL_WINDOWS)
#define MAIN_PATH       getMainPath()
#define RESOURCES       MAIN_PATH   + "resources\\"
#define LOGS_PATH       RESOURCES   + "logs\\"
#define LOGS_PATH       RESOURCES   + "errors\\"
// !BILL_WINDOWS
#elif   defined(LINUS_LINUX)
#define MAIN_PATH       getMainPath()
#define RESOURCES       MAIN_PATH   + "resources/"
#define LOGS_PATH       RESOURCES   + "logs/"
#define LOGS_PATH       WORK_DIR    + "errors/"
// !LINUS_LINUX
#else   // NUN
#define MAIN_PATH       ""
#define RESOURCES       ""
#define LOGS_PATH       ""
#define LOGS_PATH       ""
// !NUN
#endif

str_val getMainPath();

#endif // !DOM_PATHS_HPP
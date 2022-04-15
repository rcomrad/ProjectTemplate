#ifndef DOM_PATHS_HPP
#define DOM_PATHS_HPP

#ifdef LINUS_LINUX
#include <unistd.h>
#endif

#include "main/flags.hpp"
#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"

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
#endif // !LINUS_LINUX

str_val getMainPath();

#endif // !DOM_PATHS_HPP
//#define

#include <string>

#include "domain/error_message.hpp"

#include "core/core.hpp"

#include "path.hpp"

//--------------------------------------------------------------------------------
#include <fstream>
int
main(int argc, char* argv[])
{
    WRITE_LOG("Start_main");

    eval::Core core("");
    core.run(argc, argv);

    return 0;
}

//--------------------------------------------------------------------------------

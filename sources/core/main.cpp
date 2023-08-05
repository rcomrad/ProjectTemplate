#include <iostream>

#include "domain/log.hpp"

#include "core/core.hpp"

int
main(int argc, char* argv[])
{
    std::cout << "LAMPA" << std::endl;

    dom::Log::getInstance().reloadSettings();

    core::Core app;
    app.run();

    std::cout << "91" << std::endl;

    return 0;
}

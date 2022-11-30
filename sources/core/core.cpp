#include "core.hpp"

//--------------------------------------------------------------------------------

#include <iostream>

#include "domain/error_message.hpp"

//--------------------------------------------------------------------------------

eval::Core::Core(const std::string& aDatabasePath) noexcept
{
    WRITE_LOG("Creating_core");
}

//--------------------------------------------------------------------------------

void
eval::Core::run(int argc, char* argv[]) noexcept
{
    std::cout << "Boo!";
}

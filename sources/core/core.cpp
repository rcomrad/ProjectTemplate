#include "core.hpp"

#include <iostream>

#include "file_data/path.hpp"
#include "file_data/variable_storage.hpp"

core::Core::Core() noexcept
{
    auto& var = file::VariableStorage::getInstance();

    std::cout << var.getFlagUnsafe("test_flag") << std::endl;
    std::cout << var.getIntUnsafe("test_int") << std::endl;
    std::cout << var.getWordUnsafe("test_str") << std::endl;

    auto& path = file::Path::getInstance();
    std::cout << path.getPath("default").value() << std::endl;
    std::cout << path.getPath("test_path").value() << std::endl;
}

void
core::Core::run() noexcept
{
}

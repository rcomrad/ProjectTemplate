#include "core.hpp"

#include "domain/log.hpp"

#include "file_data/path.hpp"
#include "file_data/variable_storage.hpp"

core::Core::Core() noexcept
{
    auto& var = file::VariableStorage::getInstance();

    dom::writeInfo(var.getFlagUnsafe("test_flag"));
    dom::writeInfo(var.getIntUnsafe("test_int"));
    dom::writeInfo(var.getWordUnsafe("test_str"));

    auto& path = file::Path::getInstance();
    dom::writeInfo(path.getPath("default").value());
    dom::writeInfo(path.getPath("test_path").value());
}

void
core::Core::run() noexcept
{
}

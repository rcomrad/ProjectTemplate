#ifndef CORE_HPP
#define CORE_HPP

//--------------------------------------------------------------------------------

#include <string>

//--------------------------------------------------------------------------------

namespace eval
{
class Core
{
public:
    Core(const std::string& aDatabasePath) noexcept;
    ~Core() = default;

    Core(const Core& other) noexcept = default;
    Core& operator=(const Core& other) noexcept = default;

    Core(Core&& other) noexcept = default;
    Core& operator=(Core&& other) noexcept = default;

    void run(int argc, char* argv[]) noexcept;

private:
};
} // namespace eval

//--------------------------------------------------------------------------------

#endif // !CORE_HPP
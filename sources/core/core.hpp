#ifndef CORE_HPP
#define CORE_HPP

namespace core
{
class Core
{
public:
    Core() noexcept;
    ~Core() = default;

    Core(const Core& other) noexcept            = delete;
    Core& operator=(const Core& other) noexcept = delete;

    Core(Core&& other) noexcept            = delete;
    Core& operator=(Core&& other) noexcept = delete;

    void run() noexcept;
};
} // namespace core

#endif // !CORE_HPP

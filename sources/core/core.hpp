#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include <string>
#include <sstream>

#include "domain/dom_file_manager.hpp"
#include "domain/dom_path.hpp"

namespace proj
{
    class Core
    {
    public:
        Core();
        ~Core();

        void run();

    private:
        dom::File mFile;
    };
}

#endif // !CORE_HPP
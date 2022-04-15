#ifndef FILES_MANAGER_HPP
#define FILES_MANAGER_HPP

#include <fstream>

#include "main/flags.hpp"

#include "domain/dom_type.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_error_message.hpp"

void copyFile(str_const_ref aFromFileName, str_const_ref aToFileName);

namespace dom
{
    class File
    {
    public:
        File(str_const_ref aFileName);
        File(str_only_val aFileName);
        ~File();

        void write(str_const_ref aMessage);
        void write(str_only_val aMessage);

    private:
        std::ofstream mOut;
    };
} // namespace dom

#endif // !FILES_MANAGER_HPP
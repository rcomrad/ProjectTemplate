#include "domain/dom_file_manager.hpp"

void
copyFile
(
    str_const_ref aFromFileName,
    str_const_ref aToFileName
)
{
    WD_LOG("Copying file\nFrom : " << aFromFileName);
    WD_LOG("To   : " << aToFileName);
    std::ifstream fromFile(aFromFileName);
    std::ofstream toFile(aToFileName);
    std::string s;
    while (std::getline(fromFile, s, '\0')) toFile << s << '\n';
    WD_END_LOG;
}

dom::File::File(str_const_ref aFileName) :
    mOut    (aFileName)
{}

dom::File::File(str_only_val aFileName) :
    mOut    (aFileName)
{}

dom::File::~File()
{
    mOut.close();
}

void 
dom::File::write(str_const_ref aMessage)
{
    mOut << aMessage;
}

void
dom::File::write(str_only_val aMessage)
{
    write(aMessage);
}

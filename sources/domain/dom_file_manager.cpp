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

dom::File::~File()
{
    mOut.close();
}

void 
dom::File::write(const std::vector<std::string>& aMessage)
{
    for(const auto& i : aMessage) mOut << i << mDelimiter;
    mOut << '\n';
}

void
dom::File::setDelimiter(str_const_ref aDelimiter)
{
    mDelimiter = aDelimiter;
}

void
dom::File::writeEndl()
{
    mOut << '\n';
}
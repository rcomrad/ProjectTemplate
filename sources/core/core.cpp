#include "core/core.hpp"
 
proj::Core::Core() :
    mFile   (RESOURCES + "test.test")
{}

proj::Core::~Core(){}

void 
proj::Core::run()
{
    mFile.write("hello world");
}
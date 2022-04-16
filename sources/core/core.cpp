#include "core/core.hpp"

proj::Core::Core()
{
    dom::File mFile(RESOURCES + "test.test");

    dom::Pair<sint_32> p1;
    dom::Pair<sint_32, double> p2;

    p1.x = 5;
    p2.y = p1.x;

    mFile.write("hello world");
    mFile.write("hello world2", p1.x);
    mFile.write({"hello world3", "3"});

    mFile.writeEndl();
    mFile.setDelimiter(";");

    mFile.write("hello world");
    mFile.write("hello world2", p2.y);
    mFile.write({"hello world3", "3"});
}

proj::Core::~Core(){}

void 
proj::Core::run()
{
   
}
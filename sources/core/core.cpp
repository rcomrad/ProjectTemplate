#include "core/core.hpp"

proj::Core::Core()
{
    std::string path = OUTPUT_PATH + "test.test";

    dom::File mFile(OUTPUT_PATH + "test.test");

    WRITE_ERROR("CORE", "CORE", "CC#_42:", "ERROR_NOT_FOUND");

    dom::Pair<sint_32> p1;
    dom::Pair<sint_32, double> p2;

    p1.x = 5;
    p2.y = p1.x;

    mFile.write(path, "\n");

    mFile.write("hello world");
    mFile.write("hello world2", p1.x);
    mFile.write({"hello world3", "3"});

    mFile.writeEndl();
    mFile.setDelimiter(";");

    mFile.write("hello world");
    mFile.write("hello world2", p2.y);
    mFile.write({"hello world3", "3"});

    mFile.close();
    
    dom::copyFile(OUTPUT_PATH + "test.test", OUTPUT_PATH + "test2.test2");
}

proj::Core::~Core(){}

void 
proj::Core::run()
{
   
}
#include "core/core.hpp"
#include <SFML/Graphics.hpp>

proj::Core::Core()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return;



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
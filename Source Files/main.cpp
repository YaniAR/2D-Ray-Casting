#include "Wall.h"
#include "Source.h"
#include "Constants.h"

int main()
{
    sf::RenderWindow window{ sf::VideoMode(1280, 720), "RayCast", sf::Style::Close, sf::ContextSettings(24) };

    std::vector<Wall> walls;
    walls.emplace_back(300.0, 50.0, 800.0, 600.0);
    walls.emplace_back(600., 100., 800., 650.);
    walls.emplace_back(200., 200., 900., 250.);
    Source s{ 200, 650, 180 };

    
    //walls.emplace_back(600, 700, 300, 550);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                s.move(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                break;
            }
        }

        window.clear(sf::Color::Black); // Black background
        
        s.checkWalls(walls);
        s.draw(window);

        for (int i{ 0 }; i < walls.size(); ++i)
        {
            walls[i].draw(window);
        }
        window.display();  // Displays on screen
    }

    return 0;
}
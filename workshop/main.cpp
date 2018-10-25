#include <SFML/Graphics.hpp>
#include <iostream>

#include "AbstractEntity.h"
#include "CercleEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Nassim");

    // frame limit 60 fps
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("GROBOLD.ttf");


    sf::CircleShape square(80, 4);
    square.setFillColor(sf::Color(100, 250, 50));
    square.setPosition(window.getSize().x/2 - square.getGlobalBounds().width/2,
            window.getSize().y/2 - square.getGlobalBounds().height/2);

    AbstractEntity  *entity;
    EntityFactory   *factory;
    Scene           *scene;

    factory =  new EntityFactory();
    entity = factory->Create("CercleEntity");

    entity->Draw();

    scene = new Scene();
    unsigned int fps = 0;

    sf::CircleShape new_cercle(35);
    new_cercle.setFillColor(sf::Color(100, 250, 50));
    new_cercle.setPosition(14,25);

    while(window.isOpen())
    {
        int is_click = 0;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if (event.mouseButton.button == sf::Mouse::Left)
            {
                is_click = 1;
                std::cout << is_click << std::endl;
            }
        }

        scene->Update();
        fps = TimeManager::GetInstance().GetElapsedTime();


        sf::Text text(std::to_string(fps),font,11);
        text.setCharacterSize(35);
        text.setPosition(1,1);

        if (is_click == 1)
        {
            window.draw(new_cercle);
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.draw(square);
        window.display();
    }

    return (0);
}
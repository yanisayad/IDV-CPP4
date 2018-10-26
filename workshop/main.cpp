#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "AbstractEntity.h"
#include "SnakeEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

int main()
{
    // Variables
    sf::Event event;
    Scene *scene;
    unsigned int fps = 0;
    float snakeSpeed = 10;
    bool collision = false;
    bool start = true;

    sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Nassim");

    // frame limit 60 fps
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("GROBOLD.ttf");

    scene = new Scene();


    // Snake
    sf::RectangleShape snake(sf::Vector2f(50.0f,50.0f));
    snake.setFillColor(sf::Color(100, 250, 50));
    snake.setPosition(window.getSize().x/2 - snake.getGlobalBounds().width/2,
                      window.getSize().y/2 - snake.getGlobalBounds().height/2);

    while(window.isOpen())
    {
        while (start)
        {
            while(window.pollEvent(event))
            {
                sf::Vector2f PosPerso = snake.getPosition();

                if (event.type == sf::Event::Closed)
                    window.close();

                if (PosPerso.x < 1024 && PosPerso.x > 0 && PosPerso.y > 0 && PosPerso.y < 768)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        snake.move(0, -snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        snake.move(0, snakeSpeed);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        snake.move(-snakeSpeed, 0);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        snake.move(snakeSpeed, 0);
                    }
                }
                else
                {
                    start = false;
                    collision = true;
                    window.clear(sf::Color::Black);
                    sf::Text endMessage("Game Over press 'Space' to play again",font,11);
                    endMessage.setCharacterSize(50);
                    endMessage.setPosition(window.getSize().x/2 - endMessage.getGlobalBounds().width/2,
                                           window.getSize().y/2 - - snake.getGlobalBounds().height/2);

                    window.draw(endMessage);
                    window.display();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        start = true;
                        std::cout << "Je suis ici" << std::endl;
                    }

                }
            }

            if (!collision)
            {
                // fps
                scene->Update();
                fps = TimeManager::GetInstance().GetElapsedTime();

                sf::Text fps_text(std::to_string(fps),font,11);
                fps_text.setCharacterSize(35);
                fps_text.setPosition(1,1);

                window.clear(sf::Color::Black);
                window.draw(fps_text);
                window.draw(snake);
                window.display();
            }
        }
    }

    return (0);
}
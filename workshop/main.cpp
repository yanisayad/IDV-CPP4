#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "AbstractEntity.h"
#include "SnakeEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

#include "Snake.h"

int main()
{
    // Variables
    sf::Event event;
    Scene *scene;
    unsigned int fps = 0;
    float snakeSpeed = 15.5;
    bool collision = false;
    bool start = true;

    sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Nassim");

    // frame limit 60 fps
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("GROBOLD.ttf");

    scene = new Scene();


    // Snake
    Snake snake;
    snake.SetPosition(window);
    while(window.isOpen())
    {
        while (start)
        {
            while(window.pollEvent(event))
            {
                sf::Vector2f PosPerso = snake.GetPosition();

                if (event.type == sf::Event::Closed)
                    window.close();

                if (PosPerso.x < 1024 && PosPerso.x > 0 && PosPerso.y > 0 && PosPerso.y < 768)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        std::cout << "UP" << std::endl;
                        snake.MoveSnake('u', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        std::cout << "DOWN" << std::endl;
                        snake.MoveSnake('d', snakeSpeed);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        std::cout << "LEFT" << std::endl;
                        snake.MoveSnake('l', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        std::cout << "RIGHT" << std::endl;
                        snake.MoveSnake('r', snakeSpeed);
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
                                           window.getSize().y/2 - - endMessage.getGlobalBounds().height/2);

                    window.draw(endMessage);
                    window.display();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        start = true;
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
                snake.DrawSnake(window);
                window.display();
            }
        }
    }

    return (0);
}
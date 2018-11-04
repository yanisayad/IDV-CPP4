#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#include "AbstractEntity.h"
#include "SnakeEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

#include "Snake.h"
#include "Apple.h"

int main()
{
    srand(time(0));
    // Variables
    sf::Event event;
    Scene *scene;
    unsigned int fps = 0;
    float snakeSpeed = 50;
    bool collision = false;
    bool start = true;
    int appleX;
    int appleY;
    bool appleDrawPossible = true;
    bool isAppleNeeded = true;

    sf::RenderWindow window(sf::VideoMode((50 * 15), (50 * 15)), "Nassim");

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
        Apple apple;
        while (start)
        {
            // Boucle d'evenement SFML
            while(window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Position du Snake
                sf::Vector2f snakePosition = snake.GetPosition();

                // Check si on peut Draw une Apple
                if(isAppleNeeded) {
                    do {
                        appleX = apple.GeneratePosition();
                        appleY = apple.GeneratePosition();
                        if (snakePosition.x == appleX && snakePosition.y == appleY) {
                            appleDrawPossible = false;
                            break;
                        } else {
                            apple.SetPosition(appleX, appleY);
                            appleDrawPossible = true;
                        }


                    } while (!appleDrawPossible);
                    isAppleNeeded = false;
                }
                // Si le Snake passe sur une Apple
                if(snake.CheckCollision(snakePosition.x, snakePosition.y, 45, 45, appleX, appleY, 49, 49))
                {
                    isAppleNeeded = true; // On redemande une nouvelle Apple
                    // Le serpent grandit
                }

                // Condition pour check si le Snake sort de la window
                if (snakePosition.x < 702 && snakePosition.x > -1 && snakePosition.y > -1 && snakePosition.y < 702)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        snake.MoveSnake('u', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        snake.MoveSnake('d', snakeSpeed);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        snake.MoveSnake('l', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        snake.MoveSnake('r', snakeSpeed);
                    }
                }
                else // Gestion de fin de partie
                {
                    start = false;
                    collision = true;
                    window.clear(sf::Color::Black);
                    sf::Text endMessage("Game Over",font,11);
                    endMessage.setCharacterSize(50);
                    endMessage.setPosition(window.getSize().x/2 - endMessage.getGlobalBounds().width/2,
                                           window.getSize().y/2 - - endMessage.getGlobalBounds().height/2);

                    window.draw(endMessage);
                    window.display();
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

                if (appleDrawPossible) {
                    apple.DrawApple(window); // On Draw l'Apple dans la window (si possible)
                }

                snake.DrawSnake(window); // On Draw le Snake dans la window

                window.display();
            }
        }
    }

    return (0);
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "AbstractEntity.h"
#include "SnakeEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

#include "Snake.h"
#include "Apple.h"

int main()
{
    // Variables
    sf::Event event;
    Scene *scene;
    unsigned int fps = 0;
    float snakeSpeed = 15.5;
    bool collision = false;
    bool start = true;
    int appleX;
    int appleY;
    bool appleDrawPossible = true;
    bool isAppleNeeded = true;

    sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "Nassim");

    // frame limit 60 fps
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("GROBOLD.ttf");

    scene = new Scene();


    // Snake
    Snake snake;
    snake.SetPosition(window);

    // Apple
    Apple apple;


    while(window.isOpen())
    {

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
                        appleX = apple.GeneratePositionX();
                        appleY = apple.GeneratePositionY();
                        std::cout << "APPLE X " << appleX << std::endl;
                        std::cout << "APPLE Y " << appleY << std::endl;
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
                std::cout << "@Snake X " << snakePosition.x << std::endl;
                std::cout << "@Snake y " << snakePosition.y << std::endl;
                std::cout << "2eme APPLE X " << appleX << std::endl;
                std::cout << "2eme APPLE Y " << appleY << std::endl;
                // Si le Snake passe sur une Apple
                if(snake.GetX() == appleX && snake.GetY() == appleY)
                {
                    std::cout << "SNAKE EATED AN APPLE" << std::endl;
                    isAppleNeeded = true; // On redemande une nouvelle Apple
                    // Le serpent grandit
                }

                // Condition pour check si le Snake sort de la window
                if (snakePosition.x < 1024 && snakePosition.x > 0 && snakePosition.y > 0 && snakePosition.y < 768)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        std::cout << " Snake X " << snakePosition.x << std::endl;
                        std::cout << " Snake y " << snakePosition.y << std::endl;
                        snake.MoveSnake('u', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        std::cout << " Snake X " << snakePosition.x << std::endl;
                        std::cout << " Snake y " << snakePosition.y << std::endl;
                        snake.MoveSnake('d', snakeSpeed);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        std::cout << " Snake X " << snakePosition.x << std::endl;
                        std::cout << " Snake y " << snakePosition.y << std::endl;
                        snake.MoveSnake('l', snakeSpeed);
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        std::cout << " Snake X " << snakePosition.x << std::endl;
                        std::cout << " Snake y " << snakePosition.y << std::endl;
                        snake.MoveSnake('r', snakeSpeed);
                    }
                }
                else // Gestion de fin de partie
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
                snake.DrawSnake(window); // On Draw le Snake dans la window

                if (appleDrawPossible)
                    apple.DrawApple(window); // On Draw l'Apple dans la window (si possible)

                window.display();
            }
        }
    }

    return (0);
}
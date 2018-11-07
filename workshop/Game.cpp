//
// Created by Yanis on 06/11/2018.
//

#include "Game.h"
#include "Apple.h"
#include "TimeManager.h"
#include <SFML/Graphics.hpp>

Game::Game()
{
}

Game::~Game()
{
}

void Game::loopGame (sf::RenderWindow &window, sf::Event event, sf::Font font, Scene *scene, Snake snake)
{
    int appleX;
    int appleY;
    bool start             = true;
    bool isAppleNeeded     = true;
    bool collision         = false;
    bool appleDrawPossible = true;
    unsigned int fps       = 0;


    while (window.isOpen()) {
        Apple apple;
        while (start) {
            // Boucle d'evenement SFML
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Position du Snake
                sf::Vector2f snakePosition = snake.GetPosition();

                // Check si on peut Draw une Apple
                if (isAppleNeeded) {
                    do {
                        appleX = apple.GeneratePosition();
                        appleY = apple.GeneratePosition();
                        if (snakePosition.x == appleX &&
                            snakePosition.y == appleY) {
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
                if (snake.CollisionScreen(snakePosition.x, snakePosition.y, 45, 45,
                                         appleX, appleY, 49, 49)) {
                    isAppleNeeded = true; // On redemande une nouvelle Apple
                    snake.AddCase();
                }

                // Condition pour check si le Snake sort de la window
                if (snakePosition.x < 702 && snakePosition.x > -1 &&
                    snakePosition.y > -1 && snakePosition.y < 702) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        snake.ChooseDirection('u');
                    }

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        snake.ChooseDirection('d');
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        snake.ChooseDirection('l');
                    }

                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        snake.ChooseDirection('r');
                    }
                } else // Gestion de fin de partie
                {
                    collision = true;

                    window.clear(sf::Color::Black);
                    sf::Text endMessage("Game Over", font, 11);
                    endMessage.setCharacterSize(50);
                    endMessage.setPosition(window.getSize().x / 2 -
                                           endMessage.getGlobalBounds().width / 2,
                                           window.getSize().y / 2 -
                                           -endMessage.getGlobalBounds().height /
                                           2);
                    window.draw(endMessage);
                    window.display();
                }
            }
            if (!collision) {
                // fps
                scene->Update();
                fps = TimeManager::GetInstance().GetElapsedTime();

                sf::Text fps_text(std::to_string(fps), font, 11);
                fps_text.setCharacterSize(35);
                fps_text.setPosition(1, 1);

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
}
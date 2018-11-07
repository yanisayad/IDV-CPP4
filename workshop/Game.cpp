//
// Created by Yanis on 06/11/2018.
//

#include "Game.h"
#include "Apple.h"
#include "TimeManager.h"
#include <SFML/Graphics.hpp>
#include "unistd.h"

Game::Game()
{
}

Game::~Game()
{
}

int Game::loopGame (sf::RenderWindow &window, sf::Event event, sf::Font font, Scene *scene, Snake snake, int nbParty) {
    int appleX;
    int appleY;
    bool start = true;
    bool isAppleNeeded = true;
    bool collision = false;
    bool appleDrawPossible = true;
    unsigned int fps = 0;
    bool body_collision = false;

    bool right = true;
    bool left = false;
    bool up = false;
    bool down = false;
    int compteur = 0;


    while (window.isOpen()) {
        Apple apple;
        while (start) {
            // Boucle d'evenement SFML
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Condition pour check si le Snake sort de la window
/*                if (snakePosition.x < 702 && snakePosition.x > -1 &&
                    snakePosition.y > -1 && snakePosition.y < 702 && !body_collision) {*/
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        //snake.ChooseDirection('u');
                        right = false;
                        left = false;
                        up = true;
                        down = false;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        //snake.ChooseDirection('d');
                        right = false;
                        left = false;
                        up = false;
                        down = true;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        //snake.ChooseDirection('l');
                        right = false;
                        left = true;
                        up = false;
                        down = false;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        //snake.ChooseDirection('r');
                        right = true;
                        left = false;
                        up = false;
                        down = false;
                    }
                /*} else {
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

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        start = false;
                    }
                }*/
            }
            // Position du Snake
            sf::Vector2f snakePosition = snake.mSnakes[0].getPosition();

            // Check si on peut Draw une Apple
            if (isAppleNeeded) {
                appleX = apple.GeneratePosition();
                appleY = apple.GeneratePosition();
                if (snakePosition.x == apple.GetPosition().x &&
                    snakePosition.y == apple.GetPosition().y) {
                    appleDrawPossible = false;
                    break;
                } else {
                    apple.SetPosition(appleX, appleY);
                    appleDrawPossible = true;
                }
                isAppleNeeded = false;
            }

            for (unsigned int i = snake.mSnakes.size() - 1; i > 0; i--) {
                if (snake.CollisionScreen(snake.mSnakes[0].getPosition().x, snake.mSnakes[0].getPosition().y, 45,
                                          45,
                                          snake.mSnakes[i].getPosition().x, snake.mSnakes[i].getPosition().y, 49,
                                          49)) {
                    body_collision = true;
                }
            }

            if (snakePosition.x < (50 * 15) && snakePosition.x > -1 &&
                snakePosition.y > -1 && snakePosition.y < (50 * 15) && !body_collision) {
            } else {
                std::cout << "FDP DE ELSE" << std::endl;
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

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    start = false;
                }
            }

            // Si le Snake passe sur une Apple
            if (snake.CollisionScreen(snakePosition.x, snakePosition.y, 50, 50,
                                      apple.GetPosition().x, apple.GetPosition().y, 50, 50)) {
                std::cout << "NTM LA PUTE" << std::endl;
                isAppleNeeded = true; // On redemande une nouvelle Apple
                snake.AddCase();
            }

            if (compteur == 20) {
                if (up) {
                    snake.ChooseDirection('u');
                } else if (down) {
                    snake.ChooseDirection('d');
                } else if (left) {
                    snake.ChooseDirection('l');
                } else if (right) {
                    snake.ChooseDirection('r');
                }
                compteur = 0;
            }
            compteur++;

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
    return nbParty + 1;
}


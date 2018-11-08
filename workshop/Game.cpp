//
// Created by Yanis on 06/11/2018.
//

#include "Game.h"
#include "Apple.h"
#include "TimeManager.h"
#include "EntityFactory.h"
#include <SFML/Graphics.hpp>
#include "unistd.h"

Game::Game()
{
}

Game::~Game()
{
}

int Game::loopGame (sf::RenderWindow &window, sf::Event event, sf::Font font, Snake snake, int nbParty) {
    int appleX;
    int appleY;
    bool start = true;
    bool isAppleNeeded = true;
    bool collision = false;
    bool appleDrawPossible = true;
    unsigned int fps = 0;
    bool body_collision = false;
    AbstractEntity *apple;
    EntityFactory *factory;

    bool right = true;
    bool left = false;
    bool up = false;
    bool down = false;
    int compteur = 0;

    factory = new EntityFactory();
    TimeManager::GetInstance().Start();
    while (window.isOpen()) {
        apple = factory->Create("Apple");
        while (start) {
            TimeManager::GetInstance().Update();
            // Boucle d'evenement SFML
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        right = false;
                        left = false;
                        up = true;
                        down = false;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        right = false;
                        left = false;
                        up = false;
                        down = true;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        right = false;
                        left = true;
                        up = false;
                        down = false;
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        right = true;
                        left = false;
                        up = false;
                        down = false;
                    }
            }
            // Position de la tete Snake
            sf::Vector2f snakePosition = snake.mSnakes[0].getPosition();

            // Check si on peut Draw une Apple
            if (isAppleNeeded) {
                appleX = apple->GeneratePosition();
                appleY = apple->GeneratePosition();
                if (snakePosition.x == apple->GetPosition().x &&
                    snakePosition.y == apple->GetPosition().y) {
                    appleDrawPossible = false;
                    break;
                } else {
                    apple->SetPosition(appleX, appleY);
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
                    return nbParty + 1;
                }
            }

            // Si le Snake passe sur une Apple
            if (snake.CollisionScreen(snakePosition.x, snakePosition.y, 50, 50,
                                      apple->GetPosition().x, apple->GetPosition().y, 50, 50)) {
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
                fps = TimeManager::GetInstance().GetElapsedTime();
                if (fps > 60) {
                    TimeManager::GetInstance().Start();
                }

                sf::Text fps_text(std::to_string(fps), font, 11);
                fps_text.setCharacterSize(35);
                fps_text.setPosition(1, 1);

                window.clear(sf::Color::Black);
                window.draw(fps_text);

                if (appleDrawPossible) {
                    apple->Draw(window); // On Draw l'Apple dans la window (si possible)
                }

                snake.Draw(window); // On Draw le Snake dans la window

                window.display();
            }
        }
    }
}


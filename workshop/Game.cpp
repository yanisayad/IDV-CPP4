//
// Created by Yanis on 06/11/2018.
//

#include "Game.h"
#include "Apple.h"
#include "TimeManager.h"
#include "EntityFactory.h"
#include <SFML/Graphics.hpp>
#include "unistd.h"
#include "Options.h"

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
    Options *sound = new Options();

    bool right = true;
    bool left = false;
    bool up = false;
    bool down = false;
    int compteur = 0;

    std::string last_direction = "right";

    factory = new EntityFactory();
    TimeManager::GetInstance().Start();
    while (window.isOpen()) {
        apple = factory->Create("Apple");
        while (start) {
            TimeManager::GetInstance().Update();
            // Boucle d'evenement SFML
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && last_direction != "down") {
                    right = false;
                    left = false;
                    up = true;
                    down = false;
                    last_direction = "up";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && last_direction != "up") {
                    right = false;
                    left = false;
                    up = false;
                    down = true;
                    last_direction = "down";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && last_direction != "right") {
                    right = false;
                    left = true;
                    up = false;
                    down = false;
                    last_direction = "left";
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && last_direction != "left") {
                    right = true;
                    left = false;
                    up = false;
                    down = false;
                    last_direction = "right";
                }
            }
            // Position de la tete Snake
            sf::Vector2f snakePosition = snake.mSnakes[0].getPosition();

            // Check si on peut Draw une Apple
            if (isAppleNeeded) {
                appleX = apple->GeneratePosition();
                appleY = apple->GeneratePosition();
                for (unsigned int i = snake.mSnakes.size(); i > 0; i--)
                {
                    if (snake.mSnakes[i].getPosition().x == apple->GetPosition().x &&
                            snake.mSnakes[i].getPosition().y == apple->GetPosition().y)
                    {
                        appleDrawPossible = false;
                    }
                }
                apple->SetPosition(appleX, appleY);
                appleDrawPossible = true;
                isAppleNeeded = false;
            }

            for (unsigned int i = snake.mSnakes.size() - 1; i > 0; i--) {
                if (snake.CollisionScreen(snake.mSnakes[0].getPosition().x, snake.mSnakes[0].getPosition().y,
                                          snake.mSnakes[i].getPosition().x, snake.mSnakes[i].getPosition().y)) {
                    body_collision = true;
                }
            }

            if (snakePosition.x < (50 * 15) && snakePosition.x > -1 &&
                snakePosition.y > -1 && snakePosition.y < (50 * 15) && !body_collision) {
            } else {
                sound->PlaySound("sounds/gameover.ogg");
                start = false;
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

            // Si le Snake passe sur une Apple
            if (snake.CollisionScreen(snakePosition.x, snakePosition.y, apple->GetPosition().x, apple->GetPosition().y)) {

                isAppleNeeded = true; // On redemande une nouvelle Apple
                snake.Grow();
                sound->PlaySound("sounds/apple.ogg");
            }

            if (compteur == 10) {
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            return nbParty + 1;
        }
    }
}


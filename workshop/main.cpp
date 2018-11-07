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
#include "Menu.h"
#include "Game.h"

int main() {
    srand(time(0));
    // Variables
    sf::Event event;
    Scene *scene;
    Game *game;
    unsigned int fps = 0;
    float snakeSpeed = 50;
    bool collision = false;
    bool start = true;
    int appleX;
    int appleY;
    bool appleDrawPossible = true;
    bool isAppleNeeded = true;

    sf::RenderWindow window(sf::VideoMode((50 * 15), (50 * 15)), "LittleBigSnake");

    // frame limit 60 fps
    window.setFramerateLimit(60);
    Menu menu(window.getSize().x, window.getSize().y);


    sf::Font font;
    font.loadFromFile("fonts/GROBOLD.ttf");

    scene = new Scene();
    game = new Game();

    // Snake
    Snake snake;
    snake.SetPosition(window);
    while (window.isOpen()) {
        while (start) {
            window.clear();
            menu.draw(window);
            window.display();
            // Boucle d'evenement SFML
            while (window.pollEvent(event))
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;
                            case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;
                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        // BOUCLE DE JEU !!
                                        std::cout << "Plaaaaaay" << std::endl;
                                        game->loopGame(window, event, font, scene, snake);
                                        break;
                                    case 1 :
                                        std::cout << "Options" << std::endl;
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                }
        }
    }
    return 0;
}

    /*    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    // BOUCLE DE JEU !!
                                    std::cout << "Plaaaaaay"<< std::endl;
                                    // ICI IL FAUT AJOUTER LA BOUCLE DE JEU
                                    break;
                                case 1 :
                                    std::cout << "Options"<< std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();
        menu.draw(window);

        window.display();
    }
    return (0);
}

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
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            snake.MoveSnake('u', snakeSpeed);
                            break;
                        case sf::Keyboard::Down:
                            snake.MoveSnake('d', snakeSpeed);
                            break;
                        case sf::Keyboard::Left:
                            snake.MoveSnake('l', snakeSpeed);
                            break;
                        case sf::Keyboard::Right:
                            snake.MoveSnake('r', snakeSpeed);
                            break;
                        case sf::Keyboard::Escape:
                            window.close();
                        default:
                            break;
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
}*/

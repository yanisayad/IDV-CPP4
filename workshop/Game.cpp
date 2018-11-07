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
    float snakeSpeed       = 50;
    bool collision         = false;
    bool appleDrawPossible = true;
    unsigned int fps       = 0;


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
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
        }
        window.clear(sf::Color::Black);
        snake.DrawSnake(window); // On Draw le Snake dans la window
        window.display();
    }
}
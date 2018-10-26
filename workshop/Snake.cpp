//
// Created by Nassim EL HORMI on 26/10/2018.
//

#include "Snake.h"
#include <SFML/Graphics.hpp>

Snake::~Snake() {

}

void Snake::DrawSnake(sf::RenderWindow &window) {
    window.draw(snake);
}

void Snake::MoveSnake(char direction, float moveSpeed) {
    if (direction == 'u') {
        snake.move(0, -moveSpeed);
    }
    else if (direction == 'd') {
        snake.move(0, moveSpeed);
    }
    else if (direction == 'l') {
        snake.move(-moveSpeed, 0);
    }
    else if (direction == 'r') {
        snake.move(moveSpeed, 0);
    }
}

sf::Vector2f Snake::GetPosition() {
    return snake.getPosition();
}

void Snake::SetPosition(sf::RenderWindow &window) {
    snake.setPosition(window.getSize().x/2 - snake.getGlobalBounds().width/2,
                      window.getSize().y/2 - snake.getGlobalBounds().height/2);
}

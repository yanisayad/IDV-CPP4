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
    switch (direction) {
        case 'u':
            snake.move(0, -moveSpeed);
            break;
        case 'd':
            snake.move(0, moveSpeed);
            break;
        case 'l':
            snake.move(-moveSpeed, 0);
            break;
        case 'r':
            snake.move(moveSpeed, 0);
            break;
        default:
            break;
    }
}

sf::Vector2f Snake::GetPosition() {
    return snake.getPosition();
}

void Snake::SetPosition(sf::RenderWindow &window) {
    snake.setPosition(50 * 10, 50 * 3);
}

float Snake::GetX() {
    return snake.getPosition().x;
}

float Snake::GetY() {
    return snake.getPosition().y;
}

bool
Snake::CheckCollision(float snakeX, float snakeY, int snakeWidth, int snakeHeight, int appleX, int appleY, int appleWidth,
                      int appleHeight) {
    return (snakeX <= appleX + appleWidth &&
        snakeX + appleWidth >= appleX &&
        snakeY <= appleY + appleHeight &&
        snakeY + appleHeight >= appleY);
}

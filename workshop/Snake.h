//
// Created by Nassim EL HORMI on 26/10/2018.
//

#ifndef WORKSHOP_SNAKE_H
#define WORKSHOP_SNAKE_H

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "Square.h"

class Square;

class Snake {
public:
    Snake() {
        snake.setSize(sf::Vector2f(50.0f,50.0f));
        snake.setFillColor(sf::Color(100, 250, 50));
    };

    void DrawSnake(sf::RenderWindow &window);

    void MoveSnake(char direction, float moveSpeed);

    void SetPosition(sf::RenderWindow &window);

    sf::Vector2f GetPosition();

    bool CheckCollision(float snakeX, float snakeY, int snakeWidth, int snakeHeight,
            int appleX, int appleY, int appleWidth, int appleHeight);

//    std::list<Square> GetSquareList();

//    void Grow();

    float GetX();

    float GetY();

    ~Snake();
private:
    sf::RectangleShape snake;

};


#endif //WORKSHOP_SNAKE_H

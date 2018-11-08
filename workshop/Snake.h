//
// Created by Nassim EL HORMI on 26/10/2018.
//

#ifndef WORKSHOP_SNAKE_H
#define WORKSHOP_SNAKE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "AbstractEntity.h"

class Square;

class Snake {
public:
    Snake(sf::RenderWindow &window);

    void Draw(sf::RenderWindow &window);
    void ChooseDirection(char direction);
    void Grow();

    void SetPosition(sf::RenderWindow &window);

    sf::Vector2f GetPosition();
    std::vector<sf::RectangleShape> mSnakes;

    bool CollisionScreen(float snakeX, float snakeY, int snakeWidth, int snakeHeight, int appleX, int appleY, int appleWidth,
                   int appleHeight);

    float GetX();

    float GetY();

    ~Snake();
private:
    sf::RectangleShape snake;

    int mSpeed = 50;

};


#endif //WORKSHOP_SNAKE_H

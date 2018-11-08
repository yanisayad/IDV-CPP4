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

    std::vector<sf::RectangleShape> mSnakes;

    bool CollisionScreen(float snakeX, float snakeY, int appleX, int appleY);

    ~Snake();
private:
    sf::RectangleShape snake;

    int mSpeed = 50;

};


#endif //WORKSHOP_SNAKE_H

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
    Snake(sf::RenderWindow &window, int sSize, int sSpeed);

    void Draw(sf::RenderWindow &window);
    void ChooseDirection(char direction);
    void AddElementToSnake();

    void SetPosition(sf::RenderWindow &window);

    sf::Vector2f GetPosition();
    std::vector<sf::RectangleShape> mSnakes;


    bool CollisionScreen(float snakeX, float snakeY, int appleX, int appleY);

    float GetX();

    float GetY();

    ~Snake();
private:
    sf::RectangleShape snake;

    sf::Clock mClock;
    sf::CircleShape mFood;
    int mTimeToUpdate;
    int mSize;
    int mSpeed = 50;
    bool mLeft, mRight, mUp, mDown;
    float mCurrentTime;


    void CheckCollision(sf::RenderWindow &window);

};


#endif //WORKSHOP_SNAKE_H

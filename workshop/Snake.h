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

#include "Square.h"

class Square;

class Snake {
public:
    Snake(sf::RenderWindow &window, int sSize, int sSpeed);


    void DrawSnake(sf::RenderWindow &window);
    void ChooseDirection(char direction);
    void AddCase();

    void SetPosition(sf::RenderWindow &window);

    sf::Vector2f GetPosition();
    std::vector<sf::RectangleShape> mSnakes;

//    bool CheckCollision(float snakeX, float snakeY, int snakeWidth, int snakeHeight,
//            int appleX, int appleY, int appleWidth, int appleHeight);

    bool CollisionScreen(float snakeX, float snakeY, int snakeWidth, int snakeHeight, int appleX, int appleY, int appleWidth,
                   int appleHeight);

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
    char last_direction;



    void CheckCollision(sf::RenderWindow &window);

};


#endif //WORKSHOP_SNAKE_H

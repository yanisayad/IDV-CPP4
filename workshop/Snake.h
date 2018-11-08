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

    sf::Vector2f GetPosition();
    std::vector<sf::RectangleShape> mSnakes;

    static Snake *getInstance(sf::RenderWindow &window, int sSize, int sSpeed) {
        if (!singleton) {
            singleton = new Snake(window, sSize, sSpeed);
        }
        return singleton;
    }

    void DrawSnake(sf::RenderWindow &window);
    void ChooseDirection(char direction);
    void AddCase();
    bool CollisionScreen(
                float snakeX,
                float snakeY,
                int snakeWidth,
                int snakeHeight,
                int appleX,
                int appleY,
                int appleWidth,
                int appleHeight
            );

    void SetPosition(sf::RenderWindow &window);



//    bool CheckCollision(float snakeX, float snakeY, int snakeWidth, int snakeHeight,
//            int appleX, int appleY, int appleWidth, int appleHeight);



    float GetX();

    float GetY();

    ~Snake();
private:
    Snake(sf::RenderWindow &window, int sSize, int sSpeed);
    static Snake *singleton;



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

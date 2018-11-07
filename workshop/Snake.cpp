//
// Created by Nassim EL HORMI on 26/10/2018.
//

#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>


Snake::~Snake() {

}

void Snake::DrawSnake(sf::RenderWindow &window) {
    for (unsigned int i = 0; i < mSnakes.size(); i++)
        window.draw(mSnakes[i]);

}

void Snake::ChooseDirection(char direction) {
    if (mSnakes.size() > 1)
    {
        for (unsigned int i = mSnakes.size() - 1; i > 0; i--)
        {
            mSnakes[i].setPosition(mSnakes[i-1].getPosition().x, mSnakes[i-1].getPosition().y);
        }
    }

    switch (direction) {
        case 'u':
            mSnakes[0].move(0, -mSpeed);
            std::cout << mSpeed << std::endl;
            break;
        case 'd':
            mSnakes[0].move(0, mSpeed);
            break;
        case 'l':
            mSnakes[0].move(-mSpeed, 0);
            break;
        case 'r':
            mSnakes[0].move(mSpeed, 0);
            break;
        default:
            break;
    }
    //last_direction = direction;
}


sf::Vector2f Snake::GetPosition() {
    return mSnakes[0].getPosition();
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


Snake::Snake(sf::RenderWindow &window, int sSize, int sSpeed) {
    mTimeToUpdate = 250; // 1/4 second
    mCurrentTime = 0.0f;
    mLeft = mUp = mDown = false;
    mRight = true;
    srand(std::time(0));
    AddCase();
    AddCase();
    AddCase();
    AddCase();
}

void Snake::AddCase() {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(50.0f, 50.0f));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    if (mSnakes.empty())
    {
        rect.setFillColor(sf::Color::Yellow);
        rect.setPosition(50 * 10, 50 * 3);
    }
    else
    {
        rect.setFillColor(sf::Color::Green);
        rect.setPosition(mSnakes[mSnakes.size() - 1].getPosition().x - rect.getSize().x, mSnakes[mSnakes.size() - 1].getPosition().y);
    }

    mSnakes.push_back(rect);
}

bool Snake::CollisionScreen(float snakeX, float snakeY, int snakeWidth, int snakeHeight, int appleX, int appleY, int appleWidth,
                      int appleHeight) {

    int offset = 5;

    return ((snakeX <= appleX + offset) && (snakeX >= appleX - offset)) && ((snakeY <= appleY + offset) && (snakeY >= appleY - offset));
    /*return (snakeX <= appleX + appleWidth &&
            snakeX + appleWidth >= appleX &&
            snakeY <= appleY + appleHeight &&
            snakeY + appleHeight >= appleY);
            */
}

void Snake::CheckCollision(sf::RenderWindow &window)
{
    for (unsigned int i = 2; i < mSnakes.size(); i++) // Snake's boxes
    {
        if (mSnakes[0].getPosition().x == mSnakes[i].getPosition().x
            && mSnakes[0].getPosition().y == mSnakes[i].getPosition().y)
        {
            window.close();
        }
    }

    if (mSnakes[0].getPosition().x < 0 || mSnakes[0].getPosition().x + mSnakes[0].getSize().x > window.getSize().x // Window collision
        || mSnakes[0].getPosition().y < 0 || mSnakes[0].getPosition().y + mSnakes[0].getSize().y > window.getSize().y)
    {
        window.close();
    }

    if (mSnakes[0].getPosition().x == mFood.getPosition().x // Food collision
        && mSnakes[0].getPosition().y == mFood.getPosition().y)
    {
        usleep(10);
        AddCase();
    }
}



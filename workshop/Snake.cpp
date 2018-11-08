//
// Created by Nassim EL HORMI on 26/10/2018.
//

#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>

// Constructeur
Snake::Snake(sf::RenderWindow &window) {
    srand(std::time(0));
    Grow();
    Grow();
    Grow();
    Grow();
}

//Destructeur
Snake::~Snake() {

}

/* Dessine les elements du serpent
 *
 * @params sf::RenderWindow window
 *
 * return void
 */
void Snake::Draw(sf::RenderWindow &window) {
    for (unsigned int i = 0; i < mSnakes.size(); i++)
        window.draw(mSnakes[i]);

}

/* Choix de la direction du serpent
 *
 * @params char direction
 *
 * return void
 */
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
}

/* Fonction permettant que le serpent mange et ajoute les elements
 *
 * return void
 */
void Snake::Grow() {
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

/* Check les collisions
 *
 * @params float snakeX
 * @params float snakeY
 * @param  int   appleX
 * @param  int   appleY
 *
 * return bool
 */
bool Snake::CollisionScreen(float snakeX, float snakeY, int appleX, int appleY) {

    int offset = 5;

    return ((snakeX <= appleX + offset) && (snakeX >= appleX - offset)) && ((snakeY <= appleY + offset) && (snakeY >= appleY - offset));
}



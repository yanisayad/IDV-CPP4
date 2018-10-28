//
// Created by Nassim EL HORMI on 28/10/2018.
//

#include "Apple.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <iostream>
#include <unistd.h>

void Apple::DrawApple(sf::RenderWindow &window) {
    window.draw(apple);
}

sf::Vector2f Apple::GetPosition() {
    return apple.getPosition();;
}

Apple::~Apple() {

}

float Apple::RandomFloat(float min, float max) {
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min ;
}

int Apple::GeneratePositionX() {
    return (rand() % 30) * 25;
}

int Apple::GeneratePositionY() {
    return (rand() % 25) * 25;
}

void Apple::SetPosition(int x, int y) {
    apple.setPosition(x, y);
}

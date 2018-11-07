//
// Created by Nassim EL HORMI on 28/10/2018.
//

#include "Apple.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

void Apple::DrawApple(sf::RenderWindow &window) {
    window.draw(apple);
}

sf::Vector2f Apple::GetPosition() {
    return apple.getPosition();
}

Apple::~Apple() {

}

int Apple::GeneratePosition() {
    return (rand() % 15) * 50;
}



void Apple::SetPosition(int x, int y) {
    apple.setPosition(x, y);
}

//
// Created by Nassim EL HORMI on 28/10/2018.
//

#ifndef WORKSHOP_APPLE_H
#define WORKSHOP_APPLE_H

#include <SFML/Graphics.hpp>
#include "AbstractEntity.h"

class Apple : public AbstractEntity  {

public:
    Apple() {
        apple.setSize(sf::Vector2f(50.0f, 50.0f));
        apple.setFillColor(sf::Color(255, 0, 0));
    };

    virtual void Draw(sf::RenderWindow &window) override;

    void SetPosition(int x, int y);

    virtual int GeneratePosition() override;


    sf::Vector2f GetPosition();

    ~Apple();

private:
    sf::RectangleShape apple;

};


#endif //WORKSHOP_APPLE_H

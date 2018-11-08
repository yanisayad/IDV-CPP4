//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_ABSTRACTENTITY_H
#define WORKSHOP_ABSTRACTENTITY_H

#include <SFML/Graphics.hpp>

class AbstractEntity {

public:
    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual int GeneratePosition() = 0;
    virtual sf::Vector2f GetPosition() = 0;
    virtual void SetPosition(int x, int y) = 0;
    virtual ~AbstractEntity();
};


#endif //WORKSHOP_ABSTRACTENTITY_H

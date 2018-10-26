//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_SNAKEENTITY_H
#define WORKSHOP_SNAKEENTITY_H

#include "AbstractEntity.h"

#include <SFML/Graphics.hpp>

class SnakeEntity : public AbstractEntity {

public:

    virtual void Update() override;
    virtual void Draw() override;

    SnakeEntity();
    ~SnakeEntity();

};


#endif //WORKSHOP_CERCLEENTITY_H

//
// Created by Nassim EL HORMI on 28/09/2018.
//

#include "EntityFactory.h"
#include "SnakeEntity.h"

AbstractEntity *EntityFactory::Create(const std::string &str) {

    AbstractEntity *entity = nullptr;

    if (str == "SnakeEntity")
    {
        entity = new SnakeEntity();
    }
    return entity;
}

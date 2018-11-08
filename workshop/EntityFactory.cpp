//
// Created by Nassim EL HORMI on 28/09/2018.
//

#include "EntityFactory.h"
#include "Snake.h"
#include "Apple.h"

// Constructeur
AbstractEntity *EntityFactory::Create(const std::string &str) {

    AbstractEntity *entity = nullptr;

    if (str == "Apple")
    {
        entity = new Apple();
    }
    return entity;
}

//
// Created by Nassim EL HORMI on 28/09/2018.
//

#include "EntityFactory.h"
#include "CercleEntity.h"

AbstractEntity *EntityFactory::Create(const std::string &str) {

    AbstractEntity *entity = nullptr;

    if (str == "CercleEntity")
    {
        entity = new CercleEntity();
    }
    return entity;
}

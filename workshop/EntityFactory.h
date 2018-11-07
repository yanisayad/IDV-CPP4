//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_ENTITYFACTORY_H
#define WORKSHOP_ENTITYFACTORY_H

#include <iostream>
#include "AbstractEntity.h"

class EntityFactory {

public:
    AbstractEntity* Create(const std::string& str);
};


#endif //WORKSHOP_ENTITYFACTORY_H

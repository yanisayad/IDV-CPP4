//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_SCENE_H
#define WORKSHOP_SCENE_H

#include <iostream>
#include <list>
#include "AbstractEntity.h"

class Scene {


private:
    std::list<AbstractEntity*> _entities;

public:
    std::list<AbstractEntity*> GetEntities() const;
    void AddEntity(AbstractEntity* newEntity);
    void RemoveEntity(AbstractEntity* entity);
    void Update();
    Scene();
    ~Scene();

};


#endif //WORKSHOP_SCENE_H

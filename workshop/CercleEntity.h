//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_CERCLEENTITY_H
#define WORKSHOP_CERCLEENTITY_H

#include "AbstractEntity.h"

class CercleEntity : public AbstractEntity {

public:

    virtual void Update() override;
    virtual void Draw() override;

    CercleEntity();
    ~CercleEntity();

};


#endif //WORKSHOP_CERCLEENTITY_H

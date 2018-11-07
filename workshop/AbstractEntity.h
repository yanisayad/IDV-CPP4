//
// Created by Nassim EL HORMI on 28/09/2018.
//

#ifndef WORKSHOP_ABSTRACTENTITY_H
#define WORKSHOP_ABSTRACTENTITY_H


class AbstractEntity {

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~AbstractEntity();
};


#endif //WORKSHOP_ABSTRACTENTITY_H

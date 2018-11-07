//
// Created by Yanis on 06/11/2018.
//

#ifndef WORKSHOP_GAME_HH
#define WORKSHOP_GAME_HH


#include <MacTypes.h>
#include "Menu.h"
#include "Snake.h"
#include "Scene.h"

class Game {
public:
    Game();
    ~Game();

    void loopGame(sf::RenderWindow &window, sf::Event event, sf::Font font, Scene *scene, Snake snake);


protected:

};


#endif //WORKSHOP_GAME_HH

//
// Created by Yanis on 06/11/2018.
//

#ifndef WORKSHOP_GAME_HH
#define WORKSHOP_GAME_HH


#include "Menu.h"
#include "Snake.h"
#include "Scene.h"

class Game {
public:
    Game();
    ~Game();

    int loopGame(sf::RenderWindow &window, sf::Event event, sf::Font font, Scene *scene, Snake snake, int nbParty);

    //char last_touch;
protected:

};


#endif //WORKSHOP_GAME_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#include "AbstractEntity.h"
#include "EntityFactory.h"
#include "TimeManager.h"

#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "Game.h"
#include "EndMenu.h"

int main() {
    srand(time(0));
    // Variables
    sf::Event event;
    Game *game;
    bool start = true;
    int nbParty = 0;

    sf::RenderWindow window(sf::VideoMode((50 * 15), (50 * 15)), "LittleBigSnake");

    // frame limit 60 fps
    window.setFramerateLimit(60);
    Menu menu(window.getSize().x, window.getSize().y);
    EndMenu endmenu(window.getSize().x, window.getSize().y);

    sf::Font font;
    font.loadFromFile("fonts/GROBOLD.ttf");

    game = new Game();

    // Snake
    Snake snake(window);
    while (window.isOpen()) {
        while (start) {
            // Boucle d'evenement SFML
            if (nbParty == 0) {
                window.clear();
                menu.draw(window);
                window.display();
                while (window.pollEvent(event))
                    switch (event.type) {
                        case sf::Event::KeyReleased:
                            switch (event.key.code) {
                                case sf::Keyboard::Up:
                                    menu.MoveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    menu.MoveDown();
                                    break;
                                case sf::Keyboard::Return:
                                    switch (menu.GetPressedItem()) {
                                        case 0:
                                            // BOUCLE DE JEU !!
                                            nbParty = game->loopGame(window, event, font, snake,nbParty);
                                            break;
                                        case 1 :
                                            break;
                                        case 2:
                                            window.close();
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case sf::Event::Closed:
                            window.close();
                            break;
                    }
            }
            else {
                window.clear();
                endmenu.draw(window);
                window.display();
                while (window.pollEvent(event))
                    switch (event.type) {
                        case sf::Event::KeyReleased:
                            switch (event.key.code) {
                                case sf::Keyboard::Up:
                                    endmenu.MoveUp();
                                    break;
                                case sf::Keyboard::Down:
                                    endmenu.MoveDown();
                                    break;
                                case sf::Keyboard::Return:
                                    switch (endmenu.GetPressedItem()) {
                                        case 0:
                                            // BOUCLE DE JEU !!
                                            nbParty = game->loopGame(window, event, font, snake, nbParty);
                                            break;
                                        case 1:
                                            window.close();
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case sf::Event::Closed:
                            window.close();
                            break;
                    }
            }
        }
    }
    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#include "AbstractEntity.h"
#include "SnakeEntity.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "TimeManager.h"

#include "Snake.h"
#include "Apple.h"
#include "Menu.h"
#include "Game.h"

int main() {
    srand(time(0));
    // Variables
    sf::Event event;
    Scene *scene;
    Game *game;
    unsigned int fps = 0;
    float snakeSpeed = 50;
    bool collision = false;
    bool start = true;
    int appleX;
    int appleY;
    bool appleDrawPossible = true;
    bool isAppleNeeded = true;

    sf::RenderWindow window(sf::VideoMode((50 * 15), (50 * 15)), "LittleBigSnake");

    // frame limit 60 fps
    window.setFramerateLimit(60);
    Menu menu(window.getSize().x, window.getSize().y);


    sf::Font font;
    font.loadFromFile("fonts/GROBOLD.ttf");

    scene = new Scene();
    game = new Game();

    // Snake
    Snake snake(window, 50, 15);
    while (window.isOpen()) {
        while (start) {
            window.clear();
            menu.draw(window);
            window.display();
            // Boucle d'evenement SFML
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
                                        std::cout << "Plaaaaaay" << std::endl;
                                        game->loopGame(window, event, font, scene, snake);
                                        break;
                                    case 1 :
                                        std::cout << "Options" << std::endl;
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
    }
    return 0;
}

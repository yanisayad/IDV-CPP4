//
// Created by Yanis on 26/10/2018.
//

#ifndef WORKSHOP_MENU_H
#define WORKSHOP_MENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw (sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};


#endif //WORKSHOP_MENU_H

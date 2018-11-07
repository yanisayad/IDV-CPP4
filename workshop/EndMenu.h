//
// Created by Yanis on 26/10/2018.
//

#ifndef WORKSHOP_END_MENU_H
#define WORKSHOP_END_MENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS_END 2

class EndMenu {
public:
    EndMenu(float width, float height);
    ~EndMenu();

    void draw (sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {
        return selectedItemIndex;
    }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text endmenu[MAX_NUMBER_OF_ITEMS_END];
};


#endif //WORKSHOP_MENU_H
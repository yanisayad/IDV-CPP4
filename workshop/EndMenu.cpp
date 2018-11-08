//
// Created by Yanis on 26/10/2018.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include "EndMenu.h"

//Constructeur
EndMenu::EndMenu(float width, float height)
{
    if (!font.loadFromFile("fonts//GROBOLD.ttf")) {

    }

    endmenu[0].setFont(font);
    endmenu[0].setColor(sf::Color::Red);
    endmenu[0].setString("Continuer");
    endmenu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_END + 1) * 1));

    endmenu[1].setFont(font);
    endmenu[1].setColor(sf::Color::White);
    endmenu[1].setString("Quitter");
    endmenu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_END + 1) * 2));

    selectedItemIndex = 0;
}

EndMenu::~EndMenu()
{
}

/* On dessine le menu de fin
 *
 * return void
 */
void EndMenu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS_END; i++) {
        window.draw(endmenu[i]);
    }
}

/* On monte dans le menu de fin
 * return void
 */
void EndMenu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0) {
        endmenu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        endmenu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

/* On descend dans le menu de fin
 *
 * return void
 */
void EndMenu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS_END) {
        endmenu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        endmenu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
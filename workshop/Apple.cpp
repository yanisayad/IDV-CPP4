//
// Created by Nassim EL HORMI on 28/10/2018.
//

#include "Apple.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

/* On dessine la pomme
 *
 * @params sf::RenderWindow &window
 *
 * return void
 */
void Apple::Draw(sf::RenderWindow &window) {
    window.draw(apple);
}

/* On get la position de la pomme
 *
 * return sf::Vector2f
 */
sf::Vector2f Apple::GetPosition() {
    return apple.getPosition();
}

// Destructeur
Apple::~Apple() {

}

/* On genere la position de la pomme aléatoirement
 *
 * return int
 */
int Apple::GeneratePosition() {
    return (rand() % 15) * 50;
}


/* On genere la position de la pomme aléatoirement
 *
 * @params x int
 * @params y int
 *
 * return void
*/
void Apple::SetPosition(int x, int y) {
    apple.setPosition(x, y);
}

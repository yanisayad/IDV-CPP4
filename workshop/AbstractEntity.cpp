//
// Created by Nassim EL HORMI on 28/09/2018.
//

#include <SFML/Graphics.hpp>
#include "AbstractEntity.h"

/* On genere la position de la pomme aléatoirement
 *
 * @params sf::RenderWindow window
 *
 * return void
*/
void AbstractEntity::Draw(sf::RenderWindow &window) {

}

/* On genere la position de la pomme aléatoirement
 *
 * @params x int
 * @params y int
 *
 * return void
*/
void AbstractEntity::SetPosition(int x, int y) {

}

/* On genere la position de l'entité
*
* return int
*/
int AbstractEntity::GeneratePosition() {

}

/* On get la position de l'entité
*
* return sf::Vector2f
*/
sf::Vector2f AbstractEntity::GetPosition() {

}

// Destructeur
AbstractEntity::~AbstractEntity() {

}
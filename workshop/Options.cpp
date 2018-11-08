//
// Created by abenito on 08/11/18.
//

#include <string>
#include "Options.h"
#include <unistd.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>

Options::Options() {
}
Options::~Options() {

}

/* Joue le son
 *
 * @params string name
 *
 * return void
 */
void Options::PlaySound(std::string name) {
    if (music.openFromFile(name))
        music.play();
}

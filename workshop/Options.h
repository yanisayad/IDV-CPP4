//
// Created by abenito on 08/11/18.
//

#ifndef WORKSHOP_OPTIONS_H
#define WORKSHOP_OPTIONS_H

#include <unistd.h>
#include <string>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Options {
public:
    Options();
    ~Options();
    void PlaySound(std::string name);

private:
    sf::Music music;
};


#endif //WORKSHOP_OPTIONS_H

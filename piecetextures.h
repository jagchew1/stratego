//
// Created by jagch on 7/4/2023.
//

#ifndef STRATEGO_2_PIECETEXTURES_H
#define STRATEGO_2_PIECETEXTURES_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class PieceTextures{
public:
    static sf::Texture RedOne;
    static sf::Texture RedTwo;
    static sf::Texture RedThree;
    static sf::Texture RedFour;
    static sf::Texture RedFive;
    static sf::Texture RedSix;
    static sf::Texture RedSeven;
    static sf::Texture RedEight;
    static sf::Texture RedNine;
    static sf::Texture RedSpy;
    static sf::Texture RedBomb;
    static sf::Texture RedFlag;

    static sf::Texture BlueOne;
    static sf::Texture BlueTwo;
    static sf::Texture BlueThree;
    static sf::Texture BlueFour;
    static sf::Texture BlueFive;
    static sf::Texture BlueSix;
    static sf::Texture BlueSeven;
    static sf::Texture BlueEight;
    static sf::Texture BlueNine;
    static sf::Texture BlueSpy;
    static sf::Texture BlueBomb;
    static sf::Texture BlueFlag;

    static sf::Texture loadTexture(std::string str);
};

#endif //STRATEGO_2_PIECETEXTURES_H

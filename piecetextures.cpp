//
// Created by jagch on 7/4/2023.
//

#include "pieceTextures.h"

using namespace sf;

Texture PieceTextures::loadTexture(std::string str){
    sf::Texture tmp;
    if (!tmp.loadFromFile(str))
        std::cout << "Error loading file\n";
    return tmp;
}

Texture PieceTextures::RedOne = PieceTextures::loadTexture("Textures/R_One.png");
Texture PieceTextures::RedTwo = PieceTextures::loadTexture("Textures/R_Two.png");
Texture PieceTextures::RedThree = PieceTextures::loadTexture("Textures/R_Three.png");
Texture PieceTextures::RedFour = PieceTextures::loadTexture("Textures/R_Four.png");
Texture PieceTextures::RedFive = PieceTextures::loadTexture("Textures/R_Five.png");
Texture PieceTextures::RedSix = PieceTextures::loadTexture("Textures/R_Six.png");
Texture PieceTextures::RedSeven = PieceTextures::loadTexture("Textures/R_Seven.png");
Texture PieceTextures::RedEight = PieceTextures::loadTexture("Textures/R_Eight.png");
Texture PieceTextures::RedNine = PieceTextures::loadTexture("Textures/R_Nine.png");
Texture PieceTextures::RedSpy = PieceTextures::loadTexture("Textures/R_Spy.png");
Texture PieceTextures::RedBomb = PieceTextures::loadTexture("Textures/R_Bomb.png");
Texture PieceTextures::RedFlag = PieceTextures::loadTexture("Textures/R_Flag.png");

Texture PieceTextures::BlueOne = PieceTextures::loadTexture("Textures/B_One.png");
Texture PieceTextures::BlueTwo = PieceTextures::loadTexture("Textures/B_Two.png");
Texture PieceTextures::BlueThree = PieceTextures::loadTexture("Textures/B_Three.png");
Texture PieceTextures::BlueFour = PieceTextures::loadTexture("Textures/B_Four.png");
Texture PieceTextures::BlueFive = PieceTextures::loadTexture("Textures/B_Five.png");
Texture PieceTextures::BlueSix = PieceTextures::loadTexture("Textures/B_Six.png");
Texture PieceTextures::BlueSeven = PieceTextures::loadTexture("Textures/B_Seven.png");
Texture PieceTextures::BlueEight = PieceTextures::loadTexture("Textures/B_Eight.png");
Texture PieceTextures::BlueNine = PieceTextures::loadTexture("Textures/B_Nine.png");
Texture PieceTextures::BlueSpy = PieceTextures::loadTexture("Textures/B_Spy.png");
Texture PieceTextures::BlueBomb = PieceTextures::loadTexture("Textures/B_Bomb.png");
Texture PieceTextures::BlueFlag = PieceTextures::loadTexture("Textures/B_Flag.png");

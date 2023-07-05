//
// Created by jagch on 7/4/2023.
//

#include "piece.h"

void Piece::setPiece(char type, bool player, int pos, bool moved){
    setType(type);
    setPlayer(player);
    setPosition(pos);
    setMoved(moved);
    this->setTexture();
}

string Piece::toString() const{
    string str;

    str += m_player?"Red ":"Blue ";

    switch (m_type)
    {
        case '1':
            str += "1 ";
            break;
        case '2':
            str += "2 ";
            break;
        case '3':
            str += "3 ";
            break;
        case '4':
            str += "4 ";
            break;
        case '5':
            str += "5 ";
            break;
        case '6':
            str += "6 ";
            break;
        case '7':
            str += "7 ";
            break;
        case '8':
            str += "8 ";
            break;
        case '9':
            str += "9 ";
            break;
        case 'S':
            str += "Spy ";
            break;
        case 'B':
            str += "Bomb ";
            break;
        case 'F':
            str += "Flag ";
            break;
        default:
            str += "??? ";
            break;
    }

    str += "\nto position\nX: ";
    str += std::to_string((m_position%10)+1);
    str += "  Y: ";
    str += std::to_string((m_position/10)+1);
    str += '\n';


    return str;

}

void Piece::move(){
    if(m_position<=-1 || 100<=m_position){
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000));
        m_sprite.setPosition(sf::Vector2f((m_position % 10) * 100.f + 50.f, (m_position / 10) * 100.f + 50.f));
        possibleMoves.clear();
        m_moved = true;
    }
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 10) * 100.f + 50.f, (m_position / 10) * 100.f + 50.f));
        m_moved = true;
    }
    return;
}

void Piece::setTexture() {
    m_sprite = Sprite();
    switch (m_type) {
        case '1':
            m_sprite.setTexture(m_player ? PieceTextures::RedOne : PieceTextures::BlueOne);
            break;
        case '2':
            m_sprite.setTexture(m_player ? PieceTextures::RedTwo : PieceTextures::BlueTwo);
            break;
        case '3':
            m_sprite.setTexture(m_player ? PieceTextures::RedThree : PieceTextures::BlueThree);
            break;
        case '4':
            m_sprite.setTexture(m_player ? PieceTextures::RedFour : PieceTextures::BlueFour);
            break;
        case '5':
            m_sprite.setTexture(m_player ? PieceTextures::RedFive : PieceTextures::BlueFive);
            break;
        case '6':
            m_sprite.setTexture(m_player ? PieceTextures::RedSix : PieceTextures::BlueSix);
            break;
        case '7':
            m_sprite.setTexture(m_player ? PieceTextures::RedSeven : PieceTextures::BlueSeven);
            break;
        case '8':
            m_sprite.setTexture(m_player ? PieceTextures::RedEight : PieceTextures::BlueEight);
            break;
        case '9':
            m_sprite.setTexture(m_player ? PieceTextures::RedNine : PieceTextures::BlueNine);
            break;
        case 'S':
            m_sprite.setTexture(m_player ? PieceTextures::RedSpy : PieceTextures::BlueSpy);
            break;
        case 'B':
            m_sprite.setTexture(m_player ? PieceTextures::RedBomb : PieceTextures::BlueBomb);
            break;
        case 'F':
            m_sprite.setTexture(m_player ? PieceTextures::RedFlag : PieceTextures::BlueFlag);
            break;
        default:
            std::cerr << "Error piece type does not exist.\n";
            break;
    }
    if(m_type=='F') {
        m_sprite.setOrigin(Vector2f(m_sprite.getTexture()->getSize().x / 2,
                                    m_sprite.getTexture()->getSize().y / 2+.05*m_sprite.getTexture()->getSize().y));
        m_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    }else if(m_type=='B'){
        m_sprite.setOrigin(Vector2f(m_sprite.getTexture()->getSize().x / 2,
                                    m_sprite.getTexture()->getSize().y / 2+.05*m_sprite.getTexture()->getSize().y));
        m_sprite.setScale(sf::Vector2f(0.6f, 0.6f));
    }else{
        m_sprite.setOrigin(Vector2f(m_sprite.getTexture()->getSize().x / 2 + .03*m_sprite.getTexture()->getSize().x,
                                    m_sprite.getTexture()->getSize().y / 2));
        m_sprite.setScale(sf::Vector2f(0.31f, 0.31f));
    }
}
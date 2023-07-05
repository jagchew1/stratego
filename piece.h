//
// Created by jagch on 7/4/2023.
//
#ifndef STRATEGO_2_PIECE_H
#define STRATEGO_2_PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "piecetextures.h"

using namespace std;
using namespace sf;

class Piece : public Drawable{
public:
    Piece(char type = '1', bool player = true, int pos = -1, bool moved = false):
    m_type{type}, m_player{player}, m_position{-1}, m_moved{true}
    {}

    void setPiece(char type, bool player, int pos, bool moved = false);

    void setType(char ch){m_type = ch; setTexture();}

    char getType(){return m_type;}

    void setPlayer(bool bl){m_player = bl; setTexture();}
    bool getPlayer(){return m_player;}

    void setPosition(int pos){m_position = pos; move();}
    int getPosition(){return m_position;}

    void setMoved(bool moved){m_moved = moved;}
    bool getMoved(){return m_moved;}

    vector<int>& getPossibleMoves(){return possibleMoves;}

    string toString() const;

    void drawIt(RenderTarget& target, RenderStates states) const{
        this->draw(target, states);
    }



private:
    Sprite m_sprite;
    vector<int> possibleMoves;
    char m_type; //1-9, S, B, or F
    bool m_player; //true = player 1, false = player 2
    int m_position; //0-99 for squares on the board, -1 = dead
    bool m_moved;

    void setTexture();
    void move();

    virtual void draw(RenderTarget &target, RenderStates states) const{
        target.draw(m_sprite);
    }
};



#endif //STRATEGO_2_PIECE_H
//
// Created by jagch on 7/5/2023.
//

#ifndef STRATEGO_2_STRATEGOGAME_H
#define STRATEGO_2_STRATEGOGAME_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "board.h"
#include "piece.h"

using namespace sf;
using namespace std;

class StrategoGame: public Drawable{
private:
    Board board;
    std::array<Piece, 40> redPieces;
    std::array<Piece, 40> bluePieces;
    Piece* selectedPiece;
    vector<sf::RectangleShape> possibleMovesSquares;
    string lastMove;

    RectangleShape infoRestart;

    Font font;
    Text textRestart;
    Text textTurn;
    Text textSituation;
    Text textLastMove;


    bool selected;
    bool playerTurn; // true = Red turn, false = Blue Turn
    bool playerTurnCheck;
    bool gameOver; //was mate
    int turn;
    bool inWater(int x){
        if(x==42 || x==43 || x==46 || x==47 || x==52 || x==53 || x==56 || x==57){
            return true;
        }
        return false;
    }

    void createMovesSquares();

    void calcPossibleMoves();
    void calc9Moves(Piece* tmpPiece);
    void calcMoves(Piece* tmpPiece);

    void eraseMoves(Piece* tmpPiece);

    void gameIsOver();

    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    StrategoGame();

    bool getSelected(){return selected;}

    bool getGameOver(){return gameOver;}

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();



};

#endif //STRATEGO_2_STRATEGOGAME_H

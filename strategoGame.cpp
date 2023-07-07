//
// Created by jagch on 7/5/2023.
//

#include "strategoGame.h"
#include <iostream>
#include <random>

using namespace std;
using namespace sf;

int getRandomInt(int min, int max) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


StrategoGame::StrategoGame()
{
    restart();
}



void StrategoGame::restart(){

    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    gameOver = false;
    turn = 1;

    bool flag = false;
    for(int i=0;i<40;i++){
        int j = getRandomInt(1, 12);
        switch(j){
            case 1:
                redPieces[i].setPiece('1', true, i);
                bluePieces[i].setPiece('1', false, 99 - i );
                break;
            case 2:
                redPieces[i].setPiece('2', true, i);
                bluePieces[i].setPiece('2', false, 99 - i );
                break;
            case 3:
                redPieces[i].setPiece('3', true, i);
                bluePieces[i].setPiece('3', false, 99 - i );
                break;
            case 4:
                redPieces[i].setPiece('4', true, i);
                bluePieces[i].setPiece('4', false, 99 - i );
                break;
            case 5:
                redPieces[i].setPiece('5', true, i);
                bluePieces[i].setPiece('5', false, 99 - i );
                break;
            case 6:
                redPieces[i].setPiece('6', true, i);
                bluePieces[i].setPiece('6', false, 99 - i );
                break;
            case 7:
                redPieces[i].setPiece('7', true, i);
                bluePieces[i].setPiece('7', false, 99 - i );
                break;
            case 8:
                redPieces[i].setPiece('8', true, i);
                bluePieces[i].setPiece('8', false, 99 - i );
                break;
            case 9:
                redPieces[i].setPiece('9', true, i);
                bluePieces[i].setPiece('9', false, 99 - i );
                break;
            case 10:
                redPieces[i].setPiece('S', true, i);
                bluePieces[i].setPiece('S', false, 99 - i );
                break;
            case 11:
                redPieces[i].setPiece('B', true, i);
                bluePieces[i].setPiece('B', false, 99 - i );
                break;
            case 12:
                if(!flag){
                    redPieces[i].setPiece('F', true, i);
                    bluePieces[i].setPiece('F', false, 99 - i );
                    flag = true;
                }else{
                    redPieces[i].setPiece('9', true, i);
                    bluePieces[i].setPiece('9', false, 99 - i );
                }
                break;
        }
    }
    redPieces[0].setPosition(0);

    calcPossibleMoves();

    textLastMove.setString(" ");


}

void StrategoGame::updateInfo(){
    textTurn.setString("Turn: " + std::to_string(turn));
    textLastMove.setString(lastMove);
}



void StrategoGame::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(Color::Black);

    target.draw(board);

    if((selectedPiece != NULL) && (selected)){
        for(int i=0; i<possibleMovesSquares.size();i++){
            target.draw(possibleMovesSquares.at(i));
        }
    }

    for(int i=0;i<40;i++){
        target.draw(redPieces[i]);
        target.draw(bluePieces[i]);
    }
}



void StrategoGame::createMovesSquares(){

    if(selectedPiece == NULL)
        return;

    possibleMovesSquares.clear();

    for(int i : selectedPiece->getPossibleMoves()){
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((i % 10) * 100.f , (i / 10) * 100.f));
        tmp.setSize(sf::Vector2f(100.f, 100.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        possibleMovesSquares.push_back(tmp);
    }

    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selectedPiece->getPosition() % 10) * 100.f , (selectedPiece->getPosition() / 10) * 100.f));
    tmp.setSize(sf::Vector2f(100.f, 100.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    possibleMovesSquares.push_back(tmp);

    return;

}



bool StrategoGame::selectPiece(int pos){

    for(int i=0; i<40; i++){
        if(playerTurn){ // If red turn
            if(redPieces[i].getPosition() == pos){
                selectedPiece = &redPieces[i];
                selected = true;
                break;
            }
        }
        else{ // If black turn
            if(bluePieces[i].getPosition() == pos){
                selectedPiece = &bluePieces[i];
                selected = true;
                break;
            }
        }
        selected = false;
    }

    if(!selected){
        selectedPiece = NULL;
        possibleMovesSquares.clear();
        return selected;
    }


    createMovesSquares();

    return selected;
}



void StrategoGame::moveSelected(int pos){
    bool validMove{false};

    if((selectedPiece == NULL) || !selected )
        return;

    // Check pos with the Piece's possibleMoves
    for(int i : selectedPiece->getPossibleMoves()){
        if(pos == i){
            validMove = true;
            break;
        }
    }

    if(validMove){
        selectedPiece->setPosition(pos);
        lastMove = "Last Turn:\n" + selectedPiece->toString();
        for(int i=0; i<40; i++){
            if(selectedPiece->getPlayer()){ // If red
                if(bluePieces[i].getPosition() == pos){
                    if(bluePieces[i].getType()==selectedPiece->getType()){ //if same piece
                        bluePieces[i].setPosition(-1);
                        selectedPiece->setPosition(-1);
                    }else if(bluePieces[i].getType()=='B'){ //if bomb
                        if(selectedPiece->getType()=='8'){
                            bluePieces[i].setPosition(-1);
                        }else{
                            selectedPiece->setPosition(-1);
                        }
                    }else if(bluePieces[i].getType()=='F'){ //if flag
                        bluePieces[i].setPosition(-1);
                        gameIsOver();
                    }else if(bluePieces[i].getType()=='1' && selectedPiece->getType()=='S'){ //if spy & 1
                        bluePieces[i].setPosition(-1);
                    }else{ //if number/spy
                        if(bluePieces[i].getType()>selectedPiece->getType()){
                            bluePieces[i].setPosition(-1);
                        }else{
                            selectedPiece->setPosition(-1);
                        }
                    }
                    break;
                }
            }
            else{ // If blue
                if(redPieces[i].getPosition() == pos){
                    if(redPieces[i].getType()==selectedPiece->getType()){ //if same piece
                        redPieces[i].setPosition(-1);
                        selectedPiece->setPosition(-1);
                    }else if(redPieces[i].getType()=='B'){ //if bomb
                        if(selectedPiece->getType()=='8'){
                            redPieces[i].setPosition(-1);
                        }else{
                            selectedPiece->setPosition(-1);
                        }
                    }else if(redPieces[i].getType()=='F'){ //if flag
                        redPieces[i].setPosition(-1);
                        gameIsOver();
                    }else if(redPieces[i].getType()=='1' && selectedPiece->getType()=='S'){ //if spy & 1
                        redPieces[i].setPosition(-1);
                    }else{ //if number/spy
                        if(redPieces[i].getType()>selectedPiece->getType()){
                            redPieces[i].setPosition(-1);
                        }else{
                            selectedPiece->setPosition(-1);
                        }
                    }
                    break;
                }
            }
        }



        if(playerTurnCheck){
            playerTurnCheck = false;
        }

        playerTurn = !playerTurn; // Here player turn changes
        calcPossibleMoves();
    }

    selectedPiece = NULL;
    selected = false;

}



void StrategoGame::calcPossibleMoves(){

    Piece* tmpPiece;

    // LOOP for every piece
    for(int x=0; x<80; x++){

        if(x<40)
            tmpPiece = &redPieces[x];
        else
            tmpPiece = &bluePieces[x-40];
        tmpPiece->getPossibleMoves().clear();

        if(tmpPiece->getPosition() == -1)
            continue;

        // Calculate Moves for tmpPiece by piece type
        switch (tmpPiece->getType())
        {
            case '9':
                calc9Moves(tmpPiece);
                break;
            case 'F':
                break;
            case 'B':
                break;
            default:
                calcMoves(tmpPiece);
                break;
        }
    }


    // Erase illegal moves on current player's pieces
    for(int x = 0; x < 40; x++){
        if(playerTurn){
            eraseMoves(&redPieces[x]);
        }
        else{
            eraseMoves(&bluePieces[x]);
        }
    }

    updateInfo();
    turn++;
}




void StrategoGame::eraseMoves(Piece* tmpPiece){

    if(tmpPiece->getPosition() == -1)
        return;


    if(tmpPiece->getPlayer() == playerTurn){

        // Erase moves on same team pieces

        for(int i = 0; i<40; i++){
            for(int j = 0; j<tmpPiece->getPossibleMoves().size();j++){

                if(tmpPiece->getPlayer()){ // Red
                    if(tmpPiece->getPossibleMoves().at(j) == redPieces[i].getPosition()){
                        tmpPiece->getPossibleMoves().erase( tmpPiece->getPossibleMoves().begin() + j );
                        break;
                    }
                }
                else{ // Blue
                    if(tmpPiece->getPossibleMoves().at(j) == bluePieces[i].getPosition()){
                        tmpPiece->getPossibleMoves().erase( tmpPiece->getPossibleMoves().begin() + j );
                        break;
                    }
                }
            }
        }
    }
}




void StrategoGame::calcMoves(Piece* tmpPiece){

    int piecePos{tmpPiece->getPosition()};
    tmpPiece->getPossibleMoves().clear();

    if((piecePos / 10) != 0 && piecePos-10){
        if(!inWater(piecePos-10)){
            tmpPiece->getPossibleMoves().push_back(piecePos - 10);
        }
    }
    if((piecePos / 10) != 9){
        if(!inWater(piecePos + 10)){
            tmpPiece->getPossibleMoves().push_back(piecePos + 10);
        }
    }
    if((piecePos % 10) != 0)
        if(!inWater(piecePos-1)){
            tmpPiece->getPossibleMoves().push_back(piecePos - 1);
        }
    if((piecePos % 10) != 9)
        if(!inWater(piecePos+1)){
            tmpPiece->getPossibleMoves().push_back(piecePos + 1);
        }
}





void StrategoGame::calc9Moves(Piece* tmpPiece){

    int piecePos{tmpPiece->getPosition()};
    int posCounter{1};

    bool finishLoop{false};

    tmpPiece->getPossibleMoves().clear();

    // 9 moves left on X axis
    while( ((piecePos-posCounter) >= 0) && ((piecePos/10) == ((piecePos-posCounter)/10)) && !inWater(piecePos-posCounter) ){

        if(!finishLoop){
            for(int i = 0; i<40; i++){
                if(  ( redPieces[i].getPosition() == (piecePos-posCounter) ) || ( bluePieces[i].getPosition() == (piecePos-posCounter))){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }
        posCounter += 1;
    }


    // 9 moves right on X axis
    finishLoop = false;
    posCounter = 1;
    while( (piecePos/10) == ((piecePos+posCounter)/10) && !inWater(piecePos+posCounter)){
        if(!finishLoop){
            for(int i = 0; i<40; i++){
                if( (redPieces[i].getPosition() == (piecePos+posCounter)) || ( bluePieces[i].getPosition() == (piecePos+posCounter) )
                                                                             || inWater(piecePos-posCounter+1)){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }
        posCounter += 1;
    }
    //Queen moves up on Y axis
    finishLoop = false;
    posCounter = 10;
    while(((piecePos-posCounter) >= 0) && (posCounter < 100) && ((piecePos%10) == ((piecePos-posCounter)%10))
          && !inWater((piecePos-posCounter))){
        if(!finishLoop){
            for(int i = 0; i<40; i++){
                if( (redPieces[i].getPosition() == (piecePos-posCounter)) || (bluePieces[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }
        posCounter += 10;
    }

    //9 moves down on Y axis
    finishLoop = false;
    posCounter = 10;
    while(((piecePos+posCounter) <= 99) && (posCounter < 100) && ((piecePos%10) == ((piecePos+posCounter)%10)) &&
            !inWater((piecePos+posCounter))){
        if(!finishLoop){
            for(int i = 0; i<40; i++){
                if( (redPieces[i].getPosition() == (piecePos+posCounter)) || (bluePieces[i].getPosition() == (piecePos+posCounter))){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }
        posCounter += 10;
    }
}

void StrategoGame::gameIsOver() {
    gameOver=true;
}

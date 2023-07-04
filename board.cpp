//
// Created by jagch on 6/29/2023.
//

#include "board.h"

Board::Board(Color col1, Color col2){
    load(col1, col2);
}

void Board::load(Color col1, Color col2){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            m_boardSquares[j + (i*10)].setPosition(Vector2f(j*100.f, i*100.f));
            m_boardSquares[j + (i*10)].setSize(Vector2f(100.f, 100.f));
            m_boardSquares[j + (i*10)].setFillColor(col1);
            m_boardSquares[j + (i*10)].setOutlineThickness(10.f);
            m_boardSquares[j + (i*10)].setOutlineColor(col2);
        }
    }
    m_boardSquares[42].setFillColor(Color::Blue);
    m_boardSquares[43].setFillColor(Color::Blue);
    m_boardSquares[46].setFillColor(Color::Blue);
    m_boardSquares[47].setFillColor(Color::Blue);
    m_boardSquares[52].setFillColor(Color::Blue);
    m_boardSquares[53].setFillColor(Color::Blue);
    m_boardSquares[56].setFillColor(Color::Blue);
    m_boardSquares[57].setFillColor(Color::Blue);
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i=0; i<100; i++) {
        target.draw(m_boardSquares[i]);
    }
}
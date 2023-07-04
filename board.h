//
// Created by jagch on 6/29/2023.
//


#ifndef STRATEGO_2_BOARD_H
#define STRATEGO_2_BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

using namespace sf;
using namespace std;

class Board : public Drawable{
public:
    explicit Board(Color col1 = Color::White, Color col2 = Color::Black);

    void load(Color col1 = Color::White, Color col2 = Color::Black);

private:
    array<RectangleShape, 64> m_boardSquares;

    virtual void draw(RenderTarget &target, RenderStates states) const;
};

#endif //STRATEGO_2_BOARD_H

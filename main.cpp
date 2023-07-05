#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

using namespace std;
using namespace sf;

int main()
{
    Board gameboard(Color::White, Color::Black);
    Piece test_piece[100];
    for(int i=0; i<100; i++){
        test_piece[i].setPlayer((i+1)%2);
        switch(i%12) {
            case 1:
                test_piece[i].setType('1');
                break;
            case 2:
                test_piece[i].setType('2');
                break;
            case 3:
                test_piece[i].setType('3');
                break;
            case 4:
                test_piece[i].setType('4');
                break;
            case 5:
                test_piece[i].setType('5');
                break;
            case 6:
                test_piece[i].setType('6');
                break;
            case 7:
                test_piece[i].setType('7');
                break;
            case 8:
                test_piece[i].setType('8');
                break;
            case 9:
                test_piece[i].setType('9');
                break;
            case 10:
                test_piece[i].setType('S');
                break;
            case 11:
                test_piece[i].setType('B');
                break;
            default:
                test_piece[i].setType('F');
        }
        test_piece[i].setPosition(i);
    }

    RenderWindow window(
            sf::VideoMode(1000, 1000),
            "Stratego");

    while (window.isOpen())
    {
        sf::Event event;
        while (
                window.pollEvent(event))
            if (event.type ==
                sf::Event::Closed)
                window.close();

        window.clear();
        gameboard.drawIt(window, RenderStates::Default);
        for(int i=0; i<100; i++){
            test_piece[i].drawIt(window, RenderStates::Default);
        }
        window.display();
    }
    return 0;
}
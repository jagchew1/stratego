#include <SFML/Graphics.hpp>
#include "board.h"

using namespace std;
using namespace sf;

int main()
{
    Board gameboard(Color::White, Color::Black);

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
        window.display();
    }
    return 0;
}
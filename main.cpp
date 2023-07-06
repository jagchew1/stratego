#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "strategoGame.h"

using namespace std;
using namespace sf;

int main(){
    StrategoGame stratego;

    sf::RenderWindow window(sf::VideoMode(1000,1000), "Stratego", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen()){

        Event event;

        while(window.pollEvent(event)){

            if(event.type == Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == Mouse::Left){
                    if((0 <= event.mouseButton.x) && (event.mouseButton.x <= 1000) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 1000)){
                        unsigned int buttonPos{(event.mouseButton.x/100) + ((event.mouseButton.y/100) * (10 * (1000/window.getSize().y)))};

                        if(!stratego.getSelected())
                            stratego.selectPiece(buttonPos);
                        else
                            stratego.moveSelected(buttonPos);
                    }
                }
            }
        }

        window.draw(stratego);
        window.display();
        cout << stratego.getGameOver() << endl;
    }
}
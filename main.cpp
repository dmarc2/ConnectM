#include <iostream>
#include "connectM.hpp"


int main(int argc, char* argv[]) {
    if(argc != 4) {
        std::cout << "Usage: ./connectM N M H\n";
        std::cout << "Where N is the board size NxN\n";
        std::cout << ", M is the winning length\n";
        std::cout << ", and H is 0 if computer goes first\n";
        std::cout << ", else H is 1 if player goes first\n";
        exit(1);
    }

    int N = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);
    int H = std::stoi(argv[3]);

    ConnectM game(N,M,H);

    char keepGoing = ' ';
    int playerMove = 0;
    do {
        game.reset();
        std::cout << game.showBoard() << std::endl; 
        while(true) {

            do {
                std::cout << "Enter column> ";
                std::cin >> playerMove;
            }while((playerMove < 0 || playerMove >= N) || !game.move(playerMove,(H)? 1:0));
            
            std::cout << game.showBoard() << std::endl; 

            if(game.check4Win((H)? 1:0)) {
                if(H == 1) {
                    std::cout << "Human won.\n";
                }
                else {
                    std::cout << "Computer won.\n";
                }
                break;
            }
            else if(game.isBoardFull()) {
                std::cout << "It's a draw!\n";
                break;
            }

            do {
                std::cout << "Enter column> ";
                std::cin >> playerMove;
            }while((playerMove < 0 || playerMove >= N) || !game.move(playerMove,(H)? 0:1));

            std::cout << game.showBoard() << std::endl; 

            if(game.check4Win((H)? 0:1)) {
                if(H == 0) {
                    std::cout << "Human won.\n";
                }
                else {
                    std::cout << "Computer won.\n";
                }
                break;
            }
            else if(game.isBoardFull()) {
                std::cout << "It's a draw!\n";
                break;
            }
        }

        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> keepGoing;
    }while(keepGoing == 'y' || keepGoing == 'Y');

    return 0;
}

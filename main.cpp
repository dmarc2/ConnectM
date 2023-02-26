#include <iostream>
#include "connectM.hpp"


int main(int argc, char* argv[]) {
    if(argc != 4) {
        std::cout << "Usage: ./connectm N M H\n";
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
        while(true) {
            do {
                std::cout << "> ";
                std::cin >> playerMove;
            }while((playerMove < 0 || playerMove >= N) || !game.move(playerMove,1));
            
            std::cout << game.getBoardStr() << std::endl; 

            //playerNum
            if(game.check4Win(1)) {
                std::cout << "Player one won.\n";
                break;
            }

            do {
                std::cout << "> ";
                std::cin >> playerMove;
            }while((playerMove < 0 || playerMove >= N) || !game.move(playerMove,0));

            std::cout << game.getBoardStr() << std::endl; 

            if(game.check4Win(0)) {
                std::cout << "Player two won.\n";
                break;
            }
        }

        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> keepGoing;
    }while(keepGoing == 'y' || keepGoing == 'Y');

    return 0;
}

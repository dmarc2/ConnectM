#include <iostream>
#include "connectM.hpp"

int main(int argc, char* argv[]) {
    ConnectM game(8,4,1);
    game.move(0,0);
    game.move(1,1);
    game.move(0,0);
    game.move(4,1);
    game.move(3,0);
    game.move(2,1);
    std::cout << game.getBoard() << std::endl; 
    return 0;
}

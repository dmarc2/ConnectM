#include <iostream>
#include "connectM.hpp"


int main(int argc, char* argv[]) {
    ConnectM game(8,4,1);
    game.move(0,1);
    game.move(1,1);
    game.move(2,0);
    game.move(2,0);
    game.move(2,0);
    game.move(2,0);
    game.move(3,1);
    game.move(7,1);
    game.move(5,1);
    game.move(6,1);
    game.move(0,0);
    std::cout << game.getBoardStr() << std::endl; 
    std::cout << game.check4Win(0) << std::endl;
    return 0;
}

#ifndef CONNECT_M_HPP
#define CONNECT_M_HPP
#include <iostream>
#include <string>
#include "board.hpp"

const char PLAYER_ONE_HAND = 'X';
const char PLAYER_TWO_HAND = 'O';

enum states{LDIAG,VERT,RDIAG,RHORIZ};

class ConnectM {
public:
    ConnectM(int N, int M, int H);
    ConnectM(const ConnectM& obj);
    ~ConnectM();

    /*
     * This function is used to check if player one (H = 1)
     * or player two (H = 0) has won the game by having
     * M of their game pieces in a row.
     * @Param: H - The player to check (H = 1 for player one
     * and H = 0 for player two)
     */
    bool check4Win(int H);

    /*
     * This function is used by the player to make a move
     * into a column on the game board.
     * @Param: col - The column to move into 
     * @Param: H - The player to move (H = 1 for player one
     * and H = 0 for player two)
     */
    bool move(int col, int H);

    /*
     * This function is used to check if the maximum number of moves have been
     * made.
     * @Postcondition: Returns true if the board is full; otherwise, false.
     */
    bool isBoardFull();

    std::string showBoard();

    /*
     * This function is used to reset the game to a clean state.
     */
    void reset();

    void operator =(const ConnectM& rhs);
private:
    int M, H;
    int moveCount;
    Board* board;
    
    char determineCellValue(int row, int col);
    void addCellBlocks(std::string& board, int row);
    void addHorizontalBorder(std::string& board);

    int countWins(int H, int row, int col);
    bool isValidRowCol(int row, int col);
};

#endif

#ifndef CONNECT_M_HPP
#define CONNECT_M_HPP
#include <iostream>

#include <string>

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

    char** getBoard();
    std::string getBoardStr();

    void reset();

    void operator =(const ConnectM& rhs);
private:
    int N, M, H;
    char** board;
    
    void initBoard();
    void deleteBoard();
    void initBoard(char** board);
    void addCellBlocks(std::string& board, int row);
    char determineCellValue(int row, int col);
    void addHorizontalBorder(std::string& board);

    int countWins(int H, int row, int col);
    bool isValidRowCol(int row, int col);
};

#endif

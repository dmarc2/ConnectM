#ifndef CONNECT_M_HPP
#define CONNECT_M_HPP

#include <string>

const char PLAYER_ONE_HAND = 'X';
const char PLAYER_TWO_HAND = 'O';

class ConnectM {
public:
    ConnectM(int N, int M, int H);
    ConnectM(const ConnectM& obj);
    ~ConnectM();

    bool check4Win(int H);

    bool move(int col, int H);

    std::string getBoard();

    void operator =(const ConnectM& rhs);
private:
    int N, M, H;
    char** board;
    
    void initBoard();
    void deleteBoard();
    void addCellBlocks(std::string& board, int row);
    char determineCellValue(int row, int col);
    void addHorizontalBorder(std::string& board);
};

#endif

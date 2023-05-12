#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
public:
    ~Board();
    Board(int N);
    Board(const Board& obj);
    int getN();
    char get(int row, int col);
    void set(int row, int col, char c);
    char** getBoard();
    void operator =(const Board& rhs);
    void clear();
private:
    int N;
    char** board;
    void initBoard();
    void deleteBoard();
    void initBoard(char** board);
    bool isValidRowCol(int row, int col);
};

#endif

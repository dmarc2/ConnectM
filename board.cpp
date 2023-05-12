#include "board.hpp"

Board::~Board() {
    deleteBoard();
}

Board::Board(int N) {
    this->N = N;
    this->board = new char*[N];
    for(int i = 0; i < N; i++) {
        this->board[i] = new char[N];
    }
    initBoard();
}

int Board::getN() {
    return this->N;
}

Board::Board(const Board& obj) {
    if(this != &obj) {
        this->board = new char*[N];
        for(int i = 0; i < N; i++) {
            this->board[i] = new char[N];
        }
        initBoard(obj.board);
    }
}

void Board::clear() {
    this->initBoard();
}

void Board::initBoard() {
    for(int i = 0; i < this->N; i++) {
        for(int j = 0; j < this->N; j++) {
            this->board[i][j] = ' ';
        }
    }
}

void Board::initBoard(char** board) {
    for(int i = 0; i < this->N; i++) {
        for(int j = 0; j < this->N; j++) {
            this->board[i][j] = board[i][j];
        }
    }
}

void Board::deleteBoard() {
    for(int i = 0; i < N; i++) {
        delete this->board[i];
    }
    delete this->board;
}

char** Board::getBoard() {
    return this->board;
}

char Board::get(int row, int col) {
    if(isValidRowCol(row,col))
        return this->board[row][col];
    return 0;
}

void Board::set(int row, int col, char c) {
    if(isValidRowCol(row,col))
        this->board[row][col] = c;
}

bool Board::isValidRowCol(int row, int col) {
    return (row >= 0 && row < this->N && col >= 0 && col < this->N);
}

void Board::operator =(const Board& rhs) {
    if(this != &rhs) {
        /*
        this->board = new char*[N];
        for(int i = 0; i < N; i++) {
            this->board[i] = new char[N];
        }
        */
    }
}

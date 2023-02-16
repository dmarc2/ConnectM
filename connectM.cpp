#include "connectM.hpp"

ConnectM::ConnectM(int N, int M, int H) {
    this->N = N;
    this->M = M;
    this->H = H;
    this->board = new char*[N];
    for(int i = 0; i < N; i++) {
        this->board[i] = new char[N];
    }
    initBoard();
}

ConnectM::ConnectM(const ConnectM& obj) {
    if(this != &obj) {
        deleteBoard();
        this->N = obj.N;
        this->M = obj.M;
        this->H = obj.H;
        this->board = new char*[N];
        for(int i = 0; i < N; i++) {
            this->board[i] = new char[N];
        }
        //initBoard(obj.board);
    }
}


ConnectM::~ConnectM() {
    deleteBoard();
}

void ConnectM::initBoard() {
    for(int i = 0; i < this->N; i++) {
        for(int j = 0; j < this->N; j++) {
            this->board[i][j] = ' ';
        }
    }
}

void ConnectM::deleteBoard() {
    for(int i = 0; i < N; i++) {
        delete this->board[i];
    }
    delete this->board;
}

void ConnectM::operator =(const ConnectM& rhs) {
    if(this != &rhs) {
        deleteBoard();
        this->N = rhs.N;
        this->M = rhs.M;
        this->H = rhs.H;
        this->board = new char*[N];
        for(int i = 0; i < N; i++) {
            this->board[i] = new char[N];
        }
    }
}

bool ConnectM::move(int col, int H) {
    if(0 <= col && col < this->N && (H == 0 || H == 1)) {
        int row = -1;
        while(row < this->N - 1) {
            if(this->board[row+1][col] == ' ')
                row+=1;
            else break;
        }

        if(row != -1) {
            this->board[row][col] = (H)? PLAYER_ONE_HAND : PLAYER_TWO_HAND;
            return true;
        }
    }
    return false;
}

std::string ConnectM::getBoard() {
    std::string board = "    ";
    //Insert column heading numbers
    int colNumber = 0;
    while(colNumber < this->N) {
        board += " ";        
        board += std::to_string(colNumber);        
        board += "  ";        
        colNumber++;
    }
    board += "\n";

    addHorizontalBorder(board);

    //Insert each row
    int rowNumber = 0;
    while(rowNumber < this->N) {
        board += "  ";
        board += " |";
        addCellBlocks(board, rowNumber);
        addHorizontalBorder(board);
        rowNumber++;
    }
    return board;
}

void ConnectM::addCellBlocks(std::string& board, int row) {
    int col = 0;
    while(col < this->N) {
        board += " ";
        board += determineCellValue(row,col);
        board += " |";
        col++;
    }
    board += "\n";
}

char ConnectM::determineCellValue(int row, int col) {
    return this->board[row][col];
}

void ConnectM::addHorizontalBorder(std::string& board) {
    int count = 0;
    board += "   +";
    while(count < this->N) {
        board += "---+";
        count++;
    }
    board += "\n";
}

bool ConnectM::check4Win(int H) {
    return false;
}

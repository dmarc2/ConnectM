#include "connectM.hpp"

ConnectM::ConnectM(int N, int M, int H) {
    this->M = M;
    this->H = H;
    this->moveCount = 0;
    this->board = new Board(N);
}

ConnectM::ConnectM(const ConnectM& obj) {
    if(this != &obj) {
        //deleteBoard(); //May not need this since constructor is only used during declaration.
        this->M = obj.M;
        this->H = obj.H;
        this->moveCount = obj.moveCount;
        //this->board = new Board(N);
    }
}

ConnectM::~ConnectM() {
    delete board;
}

void ConnectM::operator =(const ConnectM& rhs) {
    if(this != &rhs) {
        this->M = rhs.M;
        this->H = rhs.H;
        this->moveCount = rhs.moveCount;
        *(this->board) = *(rhs.board);
    }
}

void ConnectM::reset() {
    this->board->clear();
    this->moveCount = 0;
}

bool ConnectM::move(int col, int H) {
    if(0 <= col && col < this->board->getN() && (H == 0 || H == 1)) {
        int row = -1;
        while(row < this->board->getN() - 1) {
            if(this->board->get(row+1,col) == ' ')
                row+=1;
            else break;
        }

        if(row != -1) {
            this->board->set(row,col,(H)? PLAYER_ONE_HAND : PLAYER_TWO_HAND);
            this->moveCount += 1;
            return true;
        }
    }
    return false;
}


bool ConnectM::check4Win(int H) {
    int wins = 0;
    for(int i = this->board->getN()-1; i >= 0 ; i--) {
        for(int j = 0; j < this->board->getN(); j++) {
            if(this->board->get(i,j) == (H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND) {
                wins += countWins(H,i,j);
            }
            if (wins >= 1) return wins;
        }
    }
    return false;
}

int ConnectM::countWins(int H, int row, int col) {
    int wins = 0;
    for(int i = LDIAG; i <= RHORIZ; i++) {
        int count = 1;
        switch(i) {
            case LDIAG:
                for(int j = 1; j <= this->M - 1; j++) {
                    if(isValidRowCol(row-j,col-j)) {
                        if(this->board->get(row-j,col-j) == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
                            count+=1;
                        }
                        else break;
                    }
                    else {
                        break;
                    }
                }
                if(count == this->M) {
                    wins+=1;
                }
                break;
            case VERT:
                for(int j = 1; j <= this->M - 1; j++) {
                    if(isValidRowCol(row-j,col)) {
                        if(this->board->get(row-j,col) == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
                            count+=1;
                        }
                        else break;
                    }
                    else {
                        break;
                    }
                }
                if(count == this->M) {
                    wins+=1;
                }
                break;
            case RHORIZ:
                for(int j = 1; j <= this->M - 1; j++) {
                    if(isValidRowCol(row,col+j)) {
                        if(this->board->get(row,col+j) == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
                            count+=1;
                        }
                        else break;
                    }
                    else {
                        break;
                    }
                }
                if(count == this->M) {
                    wins+=1;
                }
                break;
            case RDIAG:
                for(int j = 1; j <= this->M - 1; j++) {
                    if(isValidRowCol(row-j,col+j)) {
                        if(this->board->get(row-j,col+j) == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
                            count+=1;
                        }
                        else break;
                    }
                    else {
                        break;
                    }
                }
                if(count == this->M) {
                    wins+=1;
                }
                break;
            default:
                break;
        }
    }
    return wins;
}

bool ConnectM::isValidRowCol(int row, int col) {
    return (row >= 0 && row < this->board->getN() && col >= 0 && col < this->board->getN());
}

bool ConnectM::isBoardFull() {
    return (this->moveCount == (this->board->getN() * this->board->getN()));
}

std::string ConnectM::showBoard() {
    std::string board = "    ";
    //Insert column heading numbers
    int colNumber = 0;
    while(colNumber < this->board->getN()) {
        board += " ";        
        board += std::to_string(colNumber);        
        board += "  ";        
        colNumber++;
    }
    board += "\n";

    addHorizontalBorder(board);

    //Insert each row
    int rowNumber = 0;
    while(rowNumber < this->board->getN()) {
        board += "  ";
        board += " |";
        addCellBlocks(board, rowNumber);
        addHorizontalBorder(board);
        rowNumber++;
    }
    return board;
}

char ConnectM::determineCellValue(int row, int col) {
    return this->board->get(row,col);
}

void ConnectM::addCellBlocks(std::string& board, int row) {
    int col = 0;
    while(col < this->board->getN()) {
        board += " ";
        board += determineCellValue(row,col);
        board += " |";
        col++;
    }
    board += "\n";
}

void ConnectM::addHorizontalBorder(std::string& board) {
    int count = 0;
    board += "   +";
    while(count < this->board->getN()) {
        board += "---+";
        count++;
    }
    board += "\n";
}

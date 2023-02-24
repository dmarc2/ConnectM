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
        //deleteBoard(); //May not need this since constructor is only used during declaration.
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

void ConnectM::initBoard(char** board) {
    for(int i = 0; i < this->N; i++) {
        for(int j = 0; j < this->N; j++) {
            this->board[i][j] = board[i][j];
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

std::string ConnectM::getBoardStr() {
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
    int wins = 0;
    switch(H) {
        case 0:
            for(int i = this->N-1; i >= 0 ; i--) {
                for(int j = 0; j < this->N; j++) {
                    if(this->board[i][j] == PLAYER_TWO_HAND) {
                        wins += countWins(H,i,j);
                    }
                    if (wins >= 1) return wins;
                }
            }
            break;
        case 1:
            for(int i = this->N-1; i >= 0 ; i--) {
                for(int j = 0; j < this->N; j++) {
                    if(this->board[i][j] == PLAYER_ONE_HAND) {
                        wins += countWins(H,i,j);
                    }
                    if (wins >= 1) return wins;
                }
            }
            break;
        default:
            return false;
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
                        if(this->board[row-j][col-j] == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
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
                        if(this->board[row-j][col] == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
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
                        if(this->board[row][col+j] == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
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
                        if(this->board[row-j][col+j] == ((H)? PLAYER_ONE_HAND:PLAYER_TWO_HAND)) {
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
    return (row >= 0 && row < this->N && col >= 0 && col < this->N);
}

char** ConnectM::getBoard() {
    return this->board;
}

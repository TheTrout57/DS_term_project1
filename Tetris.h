#include <iostream>

using namespace std;
struct pos{
    int row,col;
    pos(int r, int c):row{r}, col{c}{}
};

class TetrisChain{
    public:
    TetrisChain(int r, int c)
    : rows{r}, cols{c}, last{new rowNode(cols + 1)}, currentTop{0}{
        for (int i = 0; i <= cols; i++)
            last->rowArr[i] = 1;
        last->down = last;
        last->up = last;
    }
    void insetFront();
    void printBoard();
    void insertT1(int);
    
    private:
    class rowNode{
        public:
        rowNode(int c)
        :rowArr{new int [c + 1]}{
            for (int i = 0; i < c + 1; i++)
                rowArr[i] = 0;
        }
        int *rowArr;
        rowNode *down, *up;
    };
    
    rowNode *last;
    int rows, cols;
    int currentTop;
};

void TetrisChain::insetFront(){
    rowNode *newNode = new rowNode(cols);
    newNode->down = last->down;
    newNode->up = last;
    last->down->up = newNode;
    last->down = newNode;
    currentTop++;
}

void TetrisChain::printBoard(){
    for (int i = 1; i <= rows - currentTop; i++){
        for (int j = 1; j <= cols; j++){
            cout << 0;
        }
        cout << endl;
    }
    for (rowNode *ptr = last->down; ptr != last; ptr = ptr->down){
        for (int i = 1; i <= cols; i++){
            cout << ptr->rowArr[i];
        }
        cout << endl;
    }
}

void TetrisChain::insertT1(int col){
    
    rowNode *ptr = last->down;
    while (!ptr->rowArr[col] && !ptr->rowArr[col + 1] && !ptr->rowArr[col + 2])
        ptr = ptr->down;
    
    int block[2][3] = {col, col + 1, col + 2, 0, col + 1, 0};
    if (ptr->rowArr[col + 1]){
        int i = 1;
        for (;i >= 0 && ptr->up != last; i--, ptr = ptr->up){
            for (int j = 0; j < 3; j++){
                ptr->up->rowArr[block[i][j]] = 1;
            }
        }
        for (; i >= 0; i--){
            insetFront();
            for (int j = 0; j < 3; j++){
                last->down->rowArr[block[i][j]] = 1;
            }
        } 
    }else {
        int i = 1;
        for (int j = 0; j < 3; j++){
            ptr->rowArr[block[i][j]] = 1;
        }
        i--;
        for (;i >= 0 && ptr->up != last; i--, ptr = ptr->up){
            for (int j = 0; j < 3; j++){
                ptr->up->rowArr[block[i][j]] = 1;
            }
        }
        for (; i >= 0; i--){
            insetFront();
            for (int j = 0; j < 3; j++){
                last->down->rowArr[block[i][j]] = 1;
            }
        }
    }
    
}

#include <iostream>
#include "Tetris_v.h"
#include <string>

using namespace std;

int main()
{
    int rows, cols, col;
    string move;
    cin >> rows >> cols;
    TetrisChain game(rows, cols);
    cin >> move;
    while (move != "END"){
        if (move == "T1"){
            cin >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "T2"){
            cin >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "T3"){
            cin >> col;
            col--;
            int T[] = {col, col+1, cols+2, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "T3"){
            cin >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L1"){
            cin >> col;
            col--;
            int T[] = {col, cols+1, cols+col, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L2"){
            cin >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "L3"){
            cin >> col;
            col--;
            int T[] = {col+1, cols+col+1, 2*cols+col, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L4"){
            cin >> col;
            col--;
            int T[] = {col, col+1, col+2, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "J1"){
            cin >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "J2"){
            cin >> col;
            col--;
            int T[] = {col, col+1, col+2, cols+col};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "J3"){
            cin >> col;
            col--;
            int T[] = {col, cols+col, 2*cols+col, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "J4"){
            cin >> col;
            col--;
            int T[] = {col+2, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "S1"){
            cin >> col;
            col--;
            int T[] = {col, col+1, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "S2"){
            cin >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "Z1"){
            cin >> col;
            col--;
            int T[] = {col+1, col+2, cols+col, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "Z2"){
            cin >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "I1"){
            cin >> col;
            col--;
            int T[] = {col, cols+col, 2*cols+col, 3*cols+col};
            TetrisChain block = game.createChain(4, T);
            game.addChain(block);
        }else if (move == "I2"){
            cin >> col;
            col--;
            int T[] = {col, col+1, col+2, col+3};
            TetrisChain block = game.createChain(1, T);
            game.addChain(block);
        }else if (move == "O"){
            cin >> col;
            col--;
            int T[] = {col, col+1, cols+col, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }
        cin >> move;
    }
    Node* start = game.getfirst();
    game.printBoard(start);
    return 0;
}
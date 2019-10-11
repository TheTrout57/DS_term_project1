#include <iostream>
#include "Tetris.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    ofstream ofile;
    file.open("Tetris.data", ios::in);
    ofile.open("Tetris.output", ios::out);
    int rows, cols, col;
    string move;
    file >> rows >> cols;
    TetrisChain game(rows, cols);
    file >> move;
    while (move != "End"){
        if (move == "T1"){
            file >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "T2"){
            file >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "T3"){
            file >> col;
            col--;
            int T[] = {col, col+1, col+2, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "T4"){
            file >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L1"){
            file >> col;
            col--;
            int T[] = {col, col+1, cols+col, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L2"){
            file >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "L3"){
            file >> col;
            col--;
            int T[] = {col+1, cols+col+1, 2*cols+col, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "L4"){
            file >> col;
            col--;
            int T[] = {col, col+1, col+2, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "J1"){
            file >> col;
            col--;
            int T[] = {col, col + 1, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "J2"){
            file >> col;
            col--;
            int T[] = {col, col+1, col+2, cols+col};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "J3"){
            file >> col;
            col--;
            int T[] = {col, cols+col, 2*cols+col, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "J4"){
            file >> col;
            col--;
            int T[] = {col+2, cols+col, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "S1"){
            file >> col;
            col--;
            int T[] = {col, col+1, cols+col+1, cols+col+2};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "S2"){
            file >> col;
            col--;
            int T[] = {col+1, cols+col, cols+col+1, 2*cols+col};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "Z1"){
            file >> col;
            col--;
            int T[] = {col+1, col+2, cols+col, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }else if (move == "Z2"){
            file >> col;
            col--;
            int T[] = {col, cols+col, cols+col+1, 2*cols+col+1};
            TetrisChain block = game.createChain(3, T);
            game.addChain(block);
        }else if (move == "I1"){
            file >> col;
            col--;
            int T[] = {col, cols+col, 2*cols+col, 3*cols+col};
            TetrisChain block = game.createChain(4, T);
            game.addChain(block);
        }else if (move == "I2"){
            file >> col;
            col--;
            int T[] = {col, col+1, col+2, col+3};
            TetrisChain block = game.createChain(1, T);
            game.addChain(block);
        }else if (move == "O"){
            file >> col;
            col--;
            int T[] = {col, col+1, cols+col, cols+col+1};
            TetrisChain block = game.createChain(2, T);
            game.addChain(block);
        }
        game.checkBoard();
        if (game.isEnd())
            break;
        file >> move;
    }
    Node* start = game.getfirst();
    game.printBoard(ofile , start);
    return 0;
}
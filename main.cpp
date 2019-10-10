#include <iostream>
#include "Tetris.h"

using namespace std;

int main()
{
    TetrisChain a(5,15);
    a.insertT1(1);
    a.insertT1(4);
    a.insertT1(7);
    a.insertT1(10);
    a.insertT1(13);
    a.printBoard();
    
    return 0;
}
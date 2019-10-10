#include <iostream>
#include "Tetris_v.h"

using namespace std;

int main()
{
    TetrisChain a(5,15);
    int arr[] = {6, 10, 11, 12};
    TetrisChain block = a.createChain(2, arr);
    a.addChain(block);
    Node* start = a.getfirst();
    a.printBoard(start);
    return 0;
}
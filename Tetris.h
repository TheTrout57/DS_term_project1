#include <iostream>
#include <fstream>

using namespace std;

class TetrisChain;
class Node{
    public:
    friend class TetrisChain;
    Node(int c)
    :arr{new int [c]}, link{0}{
        for (int i = 0; i < c; i++)
            arr[i] = 0;
    }
    private:
    int *arr;
    Node* link;
};
class TetrisChain{
    public:
    TetrisChain(int r, int c)
    :rows{r}, cols(c), first{0}, last{0}, chainLengh{0}{}
    TetrisChain createChain(int, int*);
    void addChain(TetrisChain);
    void concatenate(TetrisChain);
    bool isFull(Node*);
    void deleteRow(Node* a, Node* b = 0);
    void printBoard(ofstream&, Node*);
    bool isEnd();
    void checkBoard();
    Node* getfirst();
    int lengh(){
        return chainLengh;
    }
    private:
    Node *first, *last;
    int rows, cols, chainLengh;
};
TetrisChain TetrisChain::createChain(int lengh, int* a){  
    TetrisChain e(rows, cols);
    for (int i = 1; i <= lengh; i++){
        if (e.first){
            e.last->link = new Node(cols);
            e.last = e.last->link;
        }else {
            e.first = e.last = new Node(cols);
        }
    }
    for (int i = 0; i < 4; i++){
        Node* ptr = e.first;
        for (int j = 0; j < a[i] / cols; j++, ptr = ptr->link);
        ptr->arr[a[i] % cols] = 1;
    }
    e.chainLengh = lengh;
    return e;
}
void TetrisChain::addChain(TetrisChain a){
    if (first){
        bool illegal = false;
        for (int i = chainLengh; i >= 1; i--){
            Node *ptr = first, *aPtr = a.first;
            for (int j = 1; j < i; j++, ptr = ptr->link);
            Node *iteratePtr = ptr;
            for (int j = 1; j <= a.chainLengh && iteratePtr != 0; j++, aPtr = aPtr->link, iteratePtr = iteratePtr->link){
                for (int k = 0; k < cols; k++){
                    if (aPtr->arr[k] == 1 && iteratePtr->arr[k] == 1){
                        illegal = true;
                        break;
                    }
                }
                if (illegal)
                    break;    
            }
            if (illegal){
                Node *temp;
                aPtr = a.first;
                for (; ptr->link != 0 && aPtr != 0; aPtr = temp, ptr = ptr->link){
                    for (int i = 0; i < cols; i++){
                        ptr->link->arr[i] += aPtr->arr[i];
                    }
                    temp = aPtr->link;
                    a.deleteRow(aPtr);
                }
                if (aPtr != 0){
                    concatenate(a);
                }
                break;
            }
        }
        if (!illegal){
            Node *aPtr = a.first, *temp;
            for (Node *ptr = first; ptr != 0 && aPtr != 0; aPtr = temp, ptr = ptr->link){
                for (int i = 0; i < cols; i++){
                    ptr->arr[i] += aPtr->arr[i];
                }
                temp = aPtr->link;
                a.deleteRow(a.first);
            }
            if (aPtr != 0){
                concatenate(a);
            }
        }
    }else {
        concatenate(a);
    }
}
void TetrisChain::concatenate(TetrisChain a){
    if (first){
        last->link = a.first;
        last = a.last;
        chainLengh += a.chainLengh;
    }else{
        first = a.first;
        last = a.last;
        chainLengh = a.chainLengh;
    }
    a.first = a.last = 0;
}
bool TetrisChain::isFull(Node* a){
    for (int i = 0; i < cols; i++){
        if (a->arr[i] == 0)
            return false;
    }
    return true;
}
void TetrisChain::deleteRow(Node* a, Node* b){
    if (a == first){
        if (a == last)
            first = last = 0;
        else {
            first = first->link;
        }
    }
    else{
        if (a == last){
            last = b;
            b->link = 0;
        }else{
            b->link = a->link;
        }
    } 
    chainLengh--;
    delete a;    
}
void TetrisChain::printBoard(ofstream &ofile, Node* ptr){
    static int call = 1;
    if (ptr == 0 || call > rows){
        for (int i = 1; i <= rows - chainLengh; i++){
            for (int j = 0; j < cols; j++)
                ofile << 0;
            ofile << endl;
        }
    }else {
        call++;
        printBoard(ofile, ptr->link);
        for (int i = 0; i < cols; i++)
            ofile << ptr->arr[i];
        ofile << endl;
    }
}
bool TetrisChain::isEnd(){
    return (chainLengh > rows);
}
void TetrisChain::checkBoard(){
    
    for (Node *ptr = first; ptr != 0;){
        if (isFull(ptr)){
            if (ptr == first){
                deleteRow(ptr);
                ptr = first;
            }else{
                Node* m = first;
                for (; m->link != ptr; m = m->link);
                deleteRow(ptr, m);
                ptr = m->link;
            }    
        }else {
            ptr = ptr->link;
        }
    }
}
inline Node* TetrisChain::getfirst(){
    return first;
}
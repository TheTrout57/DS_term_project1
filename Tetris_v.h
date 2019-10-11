#include <iostream>

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
    void concatenate(TetrisChain&);
    bool isFull(Node*);
    void deleteRow(Node* a, Node* b = 0);
    void printBoard(Node*);
    bool isEnd();
    Node* getfirst(){
        return first;
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
                Node* temp;
                for (aPtr = a.first; ptr->link != 0 && aPtr != 0; aPtr = temp, ptr = ptr->link){
                    for (int i = 0; i < cols; i++){
                        ptr->link->arr[i] += aPtr->arr[i];
                    }
                    temp = aPtr->link;
                    a.deleteRow(a.first);
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
void TetrisChain::concatenate(TetrisChain& a){
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
    if (a == first)
        first = a->link;
    else
        b->link = a->link;
    chainLengh--;
    delete a;    
}
void TetrisChain::printBoard(Node* ptr){
    if (ptr == 0){
        for (int i = 1; i <= rows - chainLengh; i++){
            for (int j = 0; j < cols; j++)
                cout << 0;
            cout << endl;
        }
    }else {
        printBoard(ptr->link);
        for (int i = 0; i < cols; i++)
            cout << ptr->arr[i];
        cout << endl;
    }
}
bool TetrisChain::isEnd(){
    return (chainLengh > rows);
}
#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        int totSize = 0;
        int noOfElem = 0;
        int numTemp = 0; 
        T elem[totSize];
        T out[numTemp];
    
    public:
        Stack();
        Stack (const Stack&);
        Stack (int totSize);
        bool push (T element);
        bool pop (T& out);
        T back(void);
        int getNumEntries();
        ~Stack();
};

template <class T>
Stack<T>::Stack() {
    totSize = 10;
}

template <class T>
Stack<T>::Stack (const Stack& obj) {
    this -> totSize = obj.totSize;
    for (int i = 0; i < totSize; i++) {
        this -> elem[i] = obj.elem[i];
    }
}

template <class T>
Stack<T>::Stack (int totSize) {
    this -> totSize = totSize;
}

template <class T>
bool Stack<T>::push (T element) {
    if (noOfElem == totSize) {
        return false;
    }
    else {
        elem[noOfElem] = element;
        noOfElem++;
        return true;
    }
}

template <class T>
bool Stack<T>::pop (T& out) {
    if (noOfElem == 0) {
        return false;
    }
    else {
        elem[noOfElem] = out[numTemp];
        numTemp++;
        noOfElem--;
        return true;
    }
}

template <class T>
T Stack<T>::back(void) {
    return elem[noOfElem];
}

template <class T>
int Stack<T>::getNumEntries() {
    return noOfElem;
}

template <class T>
Stack<T>::~Stack() {
    cout << "Destructor has been called!" << endl;
}
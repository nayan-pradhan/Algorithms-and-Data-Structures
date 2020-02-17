/* 
    CH-231-A
    a1 p2 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *arr; //my array
        int totalSize; //total size of stack
        int position; //starting position
    public:
        Stack(); //default constructor
        Stack(const Stack&); //copy constructor
        Stack(int size); //changes size of stack
        bool push(T element); //pushes elements into stack
        bool pop(T& out); //pops elements out of stack
        T back(void); //gives last element of stack
        int getNumEntries(); //gives number of data enteries in stack
        ~Stack(); //destructor
        void printStack(); //printer function
};

//default constructor
template <class T>
Stack<T>::Stack() {
    totalSize = 10; //default size of stack
    arr = new T[totalSize]; //dynamically allocating array
    position = -1; //starts from position -1
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack&obj) {
    this -> totalSize = obj.totalSize;
    obj.arr = new T[obj.totalSize];
    for (int i = 0; i <= totalSize; i++) {
        this -> arr[i] = obj.arr[i];
    }
    this -> totalSize = obj.totalSize;
    this -> position = obj.position;
}

//parametric constructor
template <class T>
Stack<T>::Stack(int size) {
    position = -1;
    this -> totalSize = size + 1; //+1 because initial position of stack is -1
    arr = new T[totalSize];
}

//pushing elements into stack
template <class T>
bool Stack<T>::push(T element) {
    if (position + 1 == totalSize) { //if stack full
        cout << "Maximum size of stack reached!" << endl;
        return false;
    }
    else { //if there is space left in stack
        position++;
        arr[position] = element; 
        return true;
    }
}

//popping element out of stack
template <class T>
bool Stack<T>::pop(T& out) {
    if (totalSize < 0) { //if stack is empty
        cout << "Cannot pop more!" << cout;
        return false;
    }
    else { //if stack contains elements
        out = arr[position];
        cout << out << endl;
        position--;
        return true;
    }
}

//prints last element of stack
template <class T>
T Stack<T>::back(void) {
    return arr[position];
}

//prints the total number of elemtns in the stack
template <class T>
int Stack<T>::getNumEntries() {
    return position+1; // because it starts from 0 
}

//free the stack elements 
template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}

//prints the stack with a space
template <class T>
void Stack<T>::printStack() {
    for (int i = 0; i <= position; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
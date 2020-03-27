#include <iostream>

using namespace std;

template <class T, int initialSize = 10>
class Stack {
    private:
        T *arr;
        int initialSize;
        int totalSize;
        int position;
    public:
        Stack();
        Stack(const Stack&);
        Stack(int size);
        bool push(T element);
        bool pop(T& out);
        T back(void);
        int getNumEntries();
        ~Stack();
};

template <class T, int initialSize>
Stack<T, initialSize>::Stack() {
    arr = new T[initialSize];
    totalSize = initialSize;
    position = -1;
}

template <class T, int initialSize>
Stack<T, initialSize>::Stack(const Stack&obj) {
    this -> initialSize = obj.initialSize;
    obj.arr = new T[obj.initialSize];
    for (int i = 0; i < initialSize; i++) {
        this -> arr[i] = obj.arr[i];
    }
    this -> totalSize = obj.totalSize;
    this -> position = obj.position;
}

template <class T, int initialSize>
Stack<T, initialSize>::Stack(int size) {
    this -> initialSize = size;
    arr = new T[initialSize];
}

template <class T, int initialSize>
bool Stack<T, initialSize>::push(T element) {
    if (position + 1 == totalSize) {
        return false;
    }
    else {
        position++;
        arr[position] = element; 
        return true;
    }
}

template <class T, int initialSize>
bool Stack<T, initialSize>::pop(T& out) {
    int popCount = 0;
    T *out;
    out = new T[popCount];
    out[popCount] = arr[position]; 
    delete arr[position];
    popCount++;
    position--;
}

template <class T, int initialSize>
T Stack<T, initialSize>::back(void) {
    return arr[position];
}

template <class T, int initialSize>
int Stack<T, initialSize>::getNumEntries() {
    return position;
}

template <class T, int initialSize>
Stack<T, initialSize>::~Stack() {
    for (int i = 0; i < position; i++) {
        delete arr[i];
        delete out[i];
    }
}

int main() {
    Stack <int> myStack;
    Stack <int> out;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // myStack.pop();
    // myStack.pop();
    
    cout << myStack.back() << endl; 
    cout << myStack.getNumEntries() << endl;

    return 0;
}
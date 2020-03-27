#include <iostream>

using namespace std;

template <class T, int totalSize = 10>
class Stack {
    private:
        T *arr;
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
        void printStack();
};

template <class T, int totalSize>
Stack<T, totalSize>::Stack() {
    totalSize = 10;
    arr = new T[totalSize];
    position = -1;
}

template <class T, int totalSize>
Stack<T, totalSize>::Stack(const Stack&obj) {
    this -> totalSize = obj.totalSize;
    obj.arr = new T[obj.totalSize];
    for (int i = 0; i < totalSize; i++) {
        this -> arr[i] = obj.arr[i];
    }
    this -> totalSize = obj.totalSize;
    this -> position = obj.position;
}

template <class T, int totalSize>
Stack<T, totalSize>::Stack(int size) {
    this -> totalSize = size;
    arr = new T[totalSize];
}

template <class T, int totalSize>
bool Stack<T, totalSize>::push(T element) {
    if (position + 1 == totalSize) {
        return false;
    }
    else {
        position++;
        arr[position] = element; 
        return true;
    }
}

template <class T, int totalSize>
bool Stack<T, totalSize>::pop(T& out) {
    if (totalSize < 0) {
        return false;
    }
    else {
        int popCount = 0;
        T *out;
        out = new T[popCount];
        out[popCount] = arr[position]; 
        delete arr[position];
        popCount++;
        position--;
    }

}

template <class T, int totalSize>
T Stack<T, totalSize>::back(void) {
    return arr[position];
}

template <class T, int totalSize>
int Stack<T, totalSize>::getNumEntries() {
    return position;
}

template <class T, int totalSize>
Stack<T, totalSize>::~Stack() {
    for (int i = 0; i < position; i++) {
        delete arr[i];
        delete out[i];
    }
}

template <class T, int totalSize>
void Stack<T, totalSize>::printStack() {
    for (int i = 0; i < position; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack <int> myStackA;
    Stack <int> myStackB;
    myStackA.push(1);
    myStackA.push(2);
    myStackA.push(3);
    myStackA.push(4);
    myStackA.push(5);

    // myStackA.pop();
    // myStackA.pop();
    
    cout << myStackA.back() << endl; 
    cout << myStackA.getNumEntries() << endl;

    return 0;
}
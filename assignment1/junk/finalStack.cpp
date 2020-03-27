#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *arr;
        int totalSize; //total size of stack
        int position; //starting position
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

template <class T>
Stack<T>::Stack() {
    totalSize = 5;
    arr = new T[totalSize];
    position = -1;
}

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

template <class T>
Stack<T>::Stack(int size) {
    position = -1;
    this -> totalSize = size + 1; //+1 because initial position of stack is -1
    arr = new T[totalSize];
}

template <class T>
bool Stack<T>::push(T element) {
    if (position + 1 == totalSize) {
        cout << "Maximum size of stack reached!" << endl;
        return false;
    }
    else {
        position++;
        arr[position] = element; 
        return true;
    }
}

template <class T>
bool Stack<T>::pop(T& out) {
    if (totalSize < 0) {
        return false;
    }
    else {
        out = arr[position];
        cout << out << endl;
        position--;
        return true;
    }
}

template <class T>
T Stack<T>::back(void) {
    return arr[position];
}

template <class T>
int Stack<T>::getNumEntries() {
    return position+1; // because it starts from 0 
}

template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <class T>
void Stack<T>::printStack() {
    for (int i = 0; i <= position; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack <int> myStackA;
    Stack <char> myStackB(4);

    myStackA.push(1);
    myStackA.push(2);
    myStackA.push(3);
    myStackA.push(4);
    myStackA.push(5);
    myStackA.push(6);
    myStackA.push(7);

    myStackB.push('a');
    myStackB.push('b');
    myStackB.push('c');
    myStackB.push('d');
    myStackB.push('e');
    myStackB.push('f');

    cout << "Int stackA: ";
    myStackA.printStack();
    cout << "Last elem: ";
    cout << myStackA.back() << endl; 
    cout << "Number of elem: ";
    cout << myStackA.getNumEntries() << endl;

    int x;
    cout << "Popping: ";
    myStackA.pop(x);
    cout << "Popping: ";
    myStackA.pop(x);
    
    cout << "Int stackA: ";
    myStackA.printStack();
    cout << "Last elem: ";
    cout << myStackA.back() << endl; 
    cout << "Number of elem: ";
    cout << myStackA.getNumEntries() << endl;

    cout << endl;

    cout << "Char stackB: ";
    myStackB.printStack();
    cout << "Last elem: ";
    cout << myStackB.back() << endl; 
    cout << "Number of elem: ";
    cout << myStackB.getNumEntries() << endl;

    char y;
    cout << "Popping: ";
    myStackB.pop(y);
    cout << "Popping: ";
    myStackB.pop(y);

    cout << "Char stackB: ";
    myStackB.printStack();
    cout << "Last elem: ";
    cout << myStackB.back() << endl; 
    cout << "Number of elem: ";
    cout << myStackB.getNumEntries() << endl;

    return 0;
}
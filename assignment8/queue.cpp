#include <iostream>
#include <chrono>

template <class T>
class Stack {
    private:
        struct StackNode {
            T data;
            StackNode *next;
        };
        StackNode *top;
        StackNode *bottom;
        int size;
        int currentSize;
    public:
        void setSize(int newSize) {size = newSize;}
        void setCurrentSize(int newCurrentSize) {currentSize = newCurrentSize;}
        int getSize() {return size;}
        int getCurrentSize() {return currentSize;}
        bool push (T x);
        T pop();
        bool isEmpty();
        Stack(int newSize);
        Stack();
        ~Stack();
        void print();
        void emptyStack();
        T returnElem(int i);
};

//emptyStack empties the whole stack
template <class T>
void Stack<T>::emptyStack() {
    if (top == nullptr) {
        return;
    }
    struct StackNode *nextElem = bottom;
    while (top != bottom) {
        nextElem = bottom -> next;
        delete bottom;
        bottom = nextElem;
    }
    delete top;
    top = nullptr;
    bottom = nullptr;
    currentSize = -1;
}

//returnElem returns the element at a given position
template <class T>
T Stack<T>::returnElem(int pos) {
    struct StackNode *iterator = bottom;
    int i = 0;
    while (i != pos) {
        iterator = iterator -> next;
        i++;
    }
    return iterator -> data;
}

//default constructor
template <class T>
Stack<T>::Stack () {
    top = nullptr;
    bottom = nullptr;
    size = -1;
    currentSize = -1;
}

//p[arametric constructor
template <class T>
Stack<T>::Stack (int newSize) {
    top = nullptr;
    bottom = nullptr;
    size = newSize;
    currentSize = -1;
}

//push
template <class T>
bool Stack<T>::push (T x) {
    try {
        if (currentSize == size-1) {
            throw "overflow";
        }
        // std::cout << "Pushing " << x << std::endl;
        struct StackNode *newElem;
        newElem = new struct StackNode;
        newElem -> data = x;
        if (currentSize == -1) {
            top = newElem;
            bottom = newElem;
            top -> next = nullptr;
            currentSize++;
            return true;
        }
        top -> next = newElem;
        top = newElem;
        top -> next = nullptr;
        currentSize++;
        return true;
    }
    catch (...) {
        std::cout << "Stack Overflow! Cannot push!" << std::endl;
        return false;
    }
}

//pop
template <class T>
T Stack<T>::pop() {
    try {
        if (top == nullptr) {
            throw "empty";
        }
        struct StackNode *pointer = top;
        T temp = pointer -> data;
        // std::cout << "Popping ";
        if (top == bottom) {
            top = nullptr;
            bottom = nullptr;
            currentSize--;
            return temp;
        }
        delete top;
        struct StackNode *iterator = bottom;
        while (iterator -> next != top) {
            iterator = iterator -> next;
        }
        top = iterator;
        currentSize--;
        return temp;
    }
    catch (...) {
        std::cout << "Stack is empty! Unable to Pop!" << std::endl;
        return -1;
    }    
}

//isEmpty
template <class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//print
template <class T>
void Stack<T>::print() {
    try {
        if (currentSize == -1) {
            throw "no elem";
        }
        struct StackNode *pointer;
        pointer = bottom;
        while (pointer != top) {
            std::cout << pointer -> data << " ";
            pointer = pointer -> next;
        }
        if (pointer == top) {
            std::cout << pointer -> data;
        }
        std::cout << std::endl;
    }
    catch (...) {
        std::cout << "Unable to Print Empty Stack!" << std::endl;
        return;
    }
}

//destructor
template<class T>
Stack<T>::~Stack() {
    struct StackNode *nextElem;
    while (top != bottom) {
        nextElem = bottom -> next;
        delete bottom;
        bottom = nextElem;
    }
    delete bottom;
    // std::cout << "Destructor called!" << std::endl;
}

template <class T>
class Queue {
    private:
        Stack<T> myStack1;
        Stack<T> myStack2;
    public:
        bool push (T x);
        T pop();
        bool isEmpty();
        Queue(int newSize);
        Queue();
        ~Queue();
        void print();
};

template <class T>
Queue<T>::Queue() {
    Stack<T> myStack1;
    Stack<T> myStack2;    
}

template <class T>
Queue<T>::Queue(int newSize) {
    myStack1.setCurrentSize(-1);
    myStack2.setCurrentSize(-1);
    myStack1.setSize(newSize);
    myStack2.setSize(newSize);
    Stack<T> myStack1(newSize);
    Stack<T> myStack2(newSize);
}

template <class T>
bool Queue<T>::push(T x) {
    try {
        if (myStack1.getSize() == myStack1.getCurrentSize()) {
            throw "overflow";
        }
        std::cout << "Pushing " << x << std::endl;
        myStack1.push(x);
        myStack2.emptyStack();
        int i = 0;
        while (i <= myStack1.getCurrentSize()) {
            myStack2.push(myStack1.returnElem(myStack1.getCurrentSize()-i));
            i++;
        }
        return true;
    }
    catch (...) {
        std::cout << "Queue Full! Unable to Push!" << std::endl;
        return false;
    }
}

template <class T>
T Queue<T>::pop() {
    try {
        if (myStack1.getCurrentSize() == myStack1.getSize()) {
            throw "empty";
        }
        std::cout << "Popping ";
        T temp = myStack2.pop();
        myStack1.emptyStack();
        int i = 0;
        while (i <= myStack2.getCurrentSize()) {
            myStack1.push(myStack2.returnElem(myStack2.getCurrentSize()-i));
            i++;
        }
        return temp;
    }
    catch (...) {
        std::cout << "Queue Empty! Cannot Pop!" << std::endl;
        return -1;
    }
}

template <class T>
void Queue<T>::print() {
    std::cout << "My Queue: ";
    myStack2.print();
}

template <class T>
bool Queue<T>::isEmpty() {
    if (myStack2.getCurrentSize() == -1) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
Queue<T>::~Queue() {
    //destructor of the stacks are called
    //the stacks is where data is allocated
}

int main() {
    Queue<int> myQueue(5);
    for (int i = 1; i < 8; i++) {
        myQueue.push(i);
        if (i == 3) {
            myQueue.print();
        }
    }
    myQueue.print();
    while (myQueue.isEmpty() != 1) {
        std::cout << myQueue.pop() << std::endl;
        myQueue.print();
    }
    std::cout << myQueue.pop() << std::endl;
}

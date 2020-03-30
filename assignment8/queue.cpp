/* 
    CH-231-A
    8.1b cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>

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
    if (currentSize == size-1) {
        throw std::logic_error("Overflow");
        return false;
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

//pop
template <class T>
T Stack<T>::pop() {
    if (top == nullptr) {
        throw std::logic_error("Underflow");
        return false;
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
    if (currentSize == -1) {
        throw std::logic_error("Underflow");
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

//queue
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

//default constructor
template <class T>
Queue<T>::Queue() {
    myStack1.setCurrentSize(-1);
    myStack2.setCurrentSize(-1);
    myStack1.setSize(-1);
    myStack2.setSize(-1);
    Stack<T> myStack1;
    Stack<T> myStack2;    
}

//parametric constructor
template <class T>
Queue<T>::Queue(int newSize) {
    myStack1.setCurrentSize(-1);
    myStack2.setCurrentSize(-1);
    myStack1.setSize(newSize);
    myStack2.setSize(newSize);
    Stack<T> myStack1(newSize);
    Stack<T> myStack2(newSize);
}

//push method for queue
template <class T>
bool Queue<T>::push(T x) {
    if (myStack1.getSize() == myStack1.getCurrentSize()) {
        throw std::logic_error("Overflow");
        return false;
    }
    myStack1.push(x);
    myStack2.emptyStack();
    int i = 0;
    while (i <= myStack1.getCurrentSize()) {
        myStack2.push(myStack1.returnElem(myStack1.getCurrentSize()-i));
        i++;
    }
    std::cout << "Pushing " << x << std::endl;
    return true;
}

//pop method for queue
template <class T>
T Queue<T>::pop() {
    if (myStack1.getCurrentSize() == myStack1.getSize()) {
        throw std::logic_error("Underflow");
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

//printer for queue
template <class T>
void Queue<T>::print() {
    std::cout << "My Queue: ";
    myStack2.print(); //myStack2 simulates queue
}

//isEmpty method for queue
template <class T>
bool Queue<T>::isEmpty() {
    if (myStack2.getCurrentSize() == -1) {
        return true;
    }
    else {
        return false;
    }
}

//destructor
template <class T>
Queue<T>::~Queue() {
    //destructor of the stacks are called
    //the stacks is where data is allocated
}

//main
int main() {
    Queue<int> myQueue(5); //making queue of 5 elem
    try { //for pushing
        for (int i = 1; i < 8; i++) {
            myQueue.push(i); //push
            myQueue.print(); //print
        }
    }
    catch (std::logic_error) { //if overflow
        std::cout << "Queue Full!" << std::endl;
    }

    myQueue.print(); //print queue
    std::cout << "is empty: " << myQueue.isEmpty() << std::endl; //check

    try { //for popping
        while (myQueue.isEmpty() != 1) { //while queue is not empty
            std::cout << myQueue.pop() << std::endl; //pop
            myQueue.print(); //print queue
        }
        std::cout << myQueue.pop() << std::endl; //try pop in empty queue
    }
    catch (std::logic_error) { //if underflow 
        std::cout << "Queue Empty!" << std::endl;
    }
}

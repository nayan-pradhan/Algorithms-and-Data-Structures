#include <iostream>
#include <vector>
#include <chrono>

template<class T> 
class Stack{
    private:
        std::vector<T> myStack; // my stack
        struct StackNode {
            T data;
            StackNode *next;
        };
        StackNode *top;
        int size;
        int currentSize;
    public:
        bool push(T x);
        bool pop();
        bool isEmpty();
        Stack(int newSize);
        Stack();
        void print();
        bool emptyStack();
        int getSize() {return size;}
        int getCurrentSize() {return currentSize;}
        void setSize(int newSize) {size = newSize;}
        void setCurrentSize(int newCurrentSize) {currentSize = newCurrentSize;}
        T getDataIn(int i);
};

// default constructor for stack
template<class T>
Stack<T>::Stack() {
    size = -1;
    currentSize = 0;
    std::vector<T>defaultStack;
}

// parametric constructor for stack
template<class T>
Stack<T>::Stack(int newSize) {
    size = newSize;
    currentSize = 0;    
}

// push for stack
template<class T>
bool Stack<T>::push(T x) {
    //no need to check for max size here as it is already done in queue push
    // if ((currentSize) == size) { //if stack size is full!
    //     std::cout << "Overflow! Cannot Push!" << std::endl;
    //     return false;
    // }
    currentSize++; //increase currentSize counter
    myStack.push_back(x); //push in stack
    return true;
}

// isEmpty function for stack
template<class T>
bool Stack<T>::isEmpty() {
    if (currentSize == 0) { //is current size 0?
        return true; //if yes, stack is empty
    }
    else { //else
        return false; //stack has some elements
    }
}

// pop for stack
template<class T>
bool Stack<T>::pop() {
    //no need to check if no elem in stack as already done in queue pop
    // if (currentSize == 0) { //is stack empty?
    //     std::cout << "List Empty! Cannot pop any element!" << std::endl;
    //     return false;
    // }
    std::cout << "Popping " << myStack[currentSize-1] << std::endl;
    myStack.pop_back();
    currentSize--;
    return true;
}

// print for stack
template<class T>
void Stack<T>::print() {
    // no need to check because already checked in print for queue
    // if (myStack.size() == 0) { //if stack is empty, gives a message
    //     std::cout << "Stack is empty so nothing to print!" << std::endl;
    // }
    // else { //else prints
        typename std::vector<T>::iterator itr;
        for (itr = myStack.begin(); itr != myStack.end(); itr++) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;   
}

// mehtod that empties myStack
template<class T>
bool Stack<T>::emptyStack() {
    if (myStack.size() == 0) {
        return true;
    }
    else {
        currentSize = 0;
        myStack.clear();
        return true;
    }
}

template<class T>
T Stack<T>::getDataIn(int i) {
    return myStack[i];
}

// for queue
template<class T>
class Queue{
    private:
        Stack<T> myStack1;
        Stack<T> myStack2;
    public:
        Queue();
        Queue(int n);
        bool push(T elem);
        bool pop();
        bool isEmpty();
        void print();
};

// default constructor of queue calls two default constructors of stack
template<class T>
Queue<T>::Queue() {
    Stack<T> myStack1;
    Stack<T> myStack2;
}

// parametric constructor for queue makes two stacks of size n
template<class T>
Queue<T>::Queue(int n) {
    myStack1.setSize(n);
    myStack2.setSize(n);
    Stack<T> myStack1(n);
    Stack<T> myStack2(n);
}

// push method for queue
template<class T>
bool Queue<T>::push(T elem) {
    if (myStack1.getSize() == myStack1.getCurrentSize()) {
        std::cout << "Queue Full! Unable to push!" << std::endl;
        return false;
    }
    else {
        myStack1.push(elem);
        myStack2.emptyStack();
        for (int i = myStack1.getCurrentSize()-1; i >= 0; i--) { 
            myStack2.push(myStack1.getDataIn(i));
        }
        return true;
    }
}

// pop method for queue
template<class T>
bool Queue<T>::pop() {
    if (myStack2.getCurrentSize() == 0) {
        std::cout << "Queue Empty! Unable to pop!" << std::endl;
        return false;
    }
    else {
        myStack2.pop();
        myStack1.setCurrentSize(myStack2.getCurrentSize());
        myStack1.emptyStack();
        for (int i = myStack2.getCurrentSize(); i > 0; i--) { 
            myStack1.push(myStack2.getDataIn(i-1));
        }
        return true;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    if (myStack1.getCurrentSize() == myStack2.getCurrentSize() &&
            myStack1.getCurrentSize() == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
void Queue<T>::print() {
    if (myStack1.getCurrentSize() == 0) {
        std::cout << "Your Queue is empty! Nothing to print!" << std::endl;
    }
    else {
        std::cout << "Your Queue: ";
        myStack1.print();
    }
}

// main
int main() {
    Queue<int> myQueue(5);
    for (int i = 1; i < 8; i++) {
        myQueue.push(i); //pushing the element into myQueue
        myQueue.print(); //check
    }
    while (myQueue.isEmpty() != true) { //checking if queue is empty
        myQueue.print(); //check
        myQueue.pop(); //while queue is not empty, pop elements
    }
    myQueue.print(); //print queue
    myQueue.pop(); //check what happens when pop is called in empty queue
    return 0;
}
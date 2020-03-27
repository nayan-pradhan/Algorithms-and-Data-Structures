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
    std::cout << "Paramteric constructor called!" << std::endl;
    size = newSize;
    currentSize = 0;
    std::cout << "size = " << size << std::endl;
    
}

// push for stack
template<class T>
bool Stack<T>::push(T x) {
    // std::cout << "Push currentSize = " << currentSize << std::endl;
    // std::cout << "Push size = " << size <<std::endl;
    // if ((currentSize) == size) { //if stack size is full!
    //     std::cout << "Overflow! Cannot Push!" << std::endl;
    //     return false;
    // }
    // else { //if there is space in stack
    //     // std::cout << "Pushing " << x << std::endl;
    //     currentSize++; //increase currentSize counter
    //     myStack.push_back(x); //push in stack
    //     return true;
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
    // if (currentSize == 0) { //is stack empty?
    //     std::cout << "List Empty! Cannot pop any element!" << std::endl;
    //     return false;
    // }
    // else { //if not
    //     // std::cout << "Popping " << myStack[currentSize-1] << std::endl; //print
    //     myStack.pop_back(); //pop back
    //     currentSize--; //reduce currentSize
    //     return true;
    // }
    std::cout << "Popping " << myStack[currentSize-1] << std::endl;
    myStack.pop_back();
    currentSize--;
    return true;
}

// print for stack
template<class T>
void Stack<T>::print() {
    if (myStack.size() == 0) { //if stack is empty, gives a message
        std::cout << "Stack is empty so nothing to print!" << std::endl;
    }
    else { //else prints
        typename std::vector<T>::iterator itr;
        for (itr = myStack.begin(); itr != myStack.end(); itr++) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;   
    }
}

// mehtod that empties myStack
template<class T>
bool Stack<T>::emptyStack() {
    if (myStack.size() == 0) {
        return true;
    }
    else {
        myStack.empty();
        return true;
    }
}

template<class T>
T Stack<T>::getDataIn(int i) {
    return myStack[i];
}

///////////////////////////////////////////////////////////////////////////////

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
        for (int i = myStack1.getCurrentSize(); i >= 0; i--) { //check if it is -1 or 0 here IMPORTNATNTOJSOFIJSDFOPISJFOSPIJFSOI
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
        myStack1.emptyStack();
        for (int i = myStack2.getCurrentSize(); i >= 0; i--) { //same herelajflsdkjslkfjaslkfjslfkjslfkjsal;fkjas;lfdkjsa;ldfkjasfl;kajfl;akj
            myStack1.push(myStack2.getDataIn(i));
        }
        return true;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    if (myStack1.getCurrentSize() == myStack2.getCurrentSize() && myStack1.getCurrentSize() == 0) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
void Queue<T>::print() {
    myStack1.print();
}

///////////////////////////////////////////////////////////////////////////////

// main
int main() {
    Queue<int> myQueue(5);
    for (int i = 1; i < 8; i++) {
        myQueue.push(i); //pushing the element into myStack
        myQueue.print(); //check
    }
    myQueue.pop();
    std::cout << std::endl;
    myQueue.print();
    // while (myQueue.isEmpty() != true) { //checking if stack is empty
    //     myQueue.print(); //check
    //     myQueue.pop(); //while stack is not empty, pop elements
    // }
    // myQueue.print(); //print stack
    // myQueue.pop(); //check what happens when pop is called in empty stack
    return 0;
}
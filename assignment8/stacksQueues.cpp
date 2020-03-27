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
};

// default constructor
template<class T>
Stack<T>::Stack() {
    size = -1;
    currentSize = 0;
    std::vector<T>defaultStack;
}

// parametric constructor
template<class T>
Stack<T>::Stack(int newSize) {
    size = newSize;
    currentSize = 0;
    std::vector<T>myStack;
}

// push
template<class T>
bool Stack<T>::push(T x) {
    if ((currentSize) == size) { //if stack size is full!
        std::cout << "Overflow! Cannot Push!" << std::endl;
        return false;
    }
    else { //if there is space in stack
        // std::cout << "Pushing " << x << std::endl;
        currentSize++; //increase currentSize counter
        myStack.push_back(x); //push in stack
        return true;
    }
}

// isEmpty function
template<class T>
bool Stack<T>::isEmpty() {
    if (currentSize == 0) { //is current size 0?
        return true; //if yes, stack is empty
    }
    else { //else
        return false; //stack has some elements
    }
}

// pop
template<class T>
bool Stack<T>::pop() {
    if (currentSize == 0) { //is stack empty?
        std::cout << "List Empty! Cannot pop any element!" << std::endl;
        return false;
    }
    else { //if not
        // std::cout << "Popping " << myStack[currentSize-1] << std::endl; //print
        myStack.pop_back(); //pop back
        currentSize--; //reduce currentSize
        return true;
    }
}

// print
template<class T>
void Stack<T>::print() {
    if (myStack.size() == 0) { //if stack is empty, gives a message
        std::cout << "Stack is empty so nothing to print!" << std::endl;
    }
    else { //else prints
        std::cout << "My Stack: ";
        typename std::vector<T>::iterator itr;
        for (itr = myStack.begin(); itr != myStack.end(); itr++) {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;   
    }
}

int main() {
    auto startDef = std::chrono::high_resolution_clock::now();
    Stack<char> defStack; //default constructor
    auto stopDef = std::chrono::high_resolution_clock::now();
    auto durDef = std::chrono::duration_cast
        <std::chrono::nanoseconds>(stopDef - startDef);
    std::cout << "Duration Default Constructor: " << durDef.count()
        << " nanoseconds." << std::endl;
    
    auto startPar = std::chrono::high_resolution_clock::now();
    Stack<int> myStack(5); //parametric constructor
    auto stopPar = std::chrono::high_resolution_clock::now();
    auto durPar = std::chrono::duration_cast
        <std::chrono::nanoseconds>(stopPar - startPar);
    std::cout << "Duration Parametric Constructor: " << durPar.count()
        << " nanoseconds." << std::endl;

    auto startPush = std::chrono::high_resolution_clock::now();
    myStack.push(1); //push method
    auto stopPush = std::chrono::high_resolution_clock::now();
    auto durPush = std::chrono::duration_cast
        <std::chrono::nanoseconds>(stopPush - startPush);
    std::cout << "Duration Push: " << durPush.count()
         << " nanoseconds." << std::endl;

    auto startPop = std::chrono::high_resolution_clock::now();
    myStack.pop(); //pop method
    auto stopPop = std::chrono::high_resolution_clock::now();
    auto durPop = std::chrono::duration_cast
        <std::chrono::nanoseconds>(stopPop - startPop);
    std::cout << "Duration Pop: " << durPop.count() 
        << " nanoseconds." << std::endl;

    auto startIsEmpty = std::chrono::high_resolution_clock::now();
    myStack.isEmpty(); //isEmpty method
    auto stopIsEmpty = std::chrono::high_resolution_clock::now();
    auto durIsEmpty = std::chrono::duration_cast
        <std::chrono::nanoseconds>(stopIsEmpty - startIsEmpty);
    std::cout << "Duration isEmpty: " << durIsEmpty.count()
        << " nanoseconds."  << std::endl;
}


//i used this main to test all the methods and functions
/*
// main
int main() {
    Stack<int> myStack(5); //creating a stack with 5 elements
    //filling stack with integers from 1 to 5, other values overflow
    for (int i = 1; i < 8; i++) {
        myStack.print(); //check
        myStack.push(i); //pushing the element into myStack
    }

    //emptying my stack by pop
    while (myStack.isEmpty() != true) { //checking if stack is empty
        myStack.print(); //check
        myStack.pop(); //while stack is not empty, pop elements
    }
    myStack.print(); //print stack
    myStack.pop(); //check what happens when pop is called in empty stack

    return 0;
}
*/
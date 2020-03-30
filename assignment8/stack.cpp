/* 
    CH-231-A
    8.1a cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

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
        bool push (T x);
        T pop();
        bool isEmpty();
        Stack(int newSize);
        Stack();
        ~Stack();
        void print();
};

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
        throw std::logic_error("Stack Full");
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
        throw std::logic_error("Empty Stack");
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
        throw std::logic_error("Empty Stack");
    }
    // std::cout << "myStack: "; 
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

/* 
//main
int main() {
    Stack<int> myStack(5); //making a stack of 5 elements
    try { //for pushing
        for (int i = 1; i < 8; i++) { //push more than 5 elem
            myStack.push(i); //push
            myStack.print(); //print
        }
    }
    catch (std::logic_error) { //when overflow
        std::cout << "Stack is Full!" << std::endl;
    }

    std::cout << "is empty: " << myStack.isEmpty() << std::endl;

    try {    
        while (myStack.isEmpty() != 1) {
            std::cout << myStack.pop() << std::endl;
            myStack.print();
        }
    }
    catch(std::logic_error) {
        std::cout << "Stack is Empty!" << std::endl;
    }
    std::cout << "is empty: " << myStack.isEmpty() << std::endl;
}
*/

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
#include <iostream>
#include "Stack.h"
using namespace std;

int main () {
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
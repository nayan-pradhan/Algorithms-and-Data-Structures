/* 
    CH-231-A
    a1 p2 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include "Stack.h"
using namespace std;

//main function
int main() {
    Stack <int> myStackA; //makes an int stack using default constructor
    Stack <char> myStackB(4); //makes a char stack using parametric constructor

    //for pushing elements into the int stack
    myStackA.push(1);
    myStackA.push(2);
    myStackA.push(3);
    myStackA.push(4);
    myStackA.push(5);
    myStackA.push(6);
    myStackA.push(7);

    //for pushing the elements into the stack
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

    //popping
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

    //popping
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
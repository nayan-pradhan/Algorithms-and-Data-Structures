/* 
    CH-231-A
    a1 p3 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include "LinkedList.h"

int main() {
    //for int data type
    linkedList<int> DLL;
    DLL.addToFront (3); //add to front
    DLL.toPrint(); //print list
    DLL.numOfElements(); //print number of elements
    DLL.addToEnd (4); //add to end
    DLL.toPrint(); //print list
    DLL.addToFront (2); //add to front
    DLL.toPrint(); //print list
    DLL.addToFront (1); //add to front
    DLL.toPrint(); //print list
    DLL.addToEnd (5); //add to end
    DLL.toPrint(); //print list
    DLL.addToEnd (6); //add to end
    DLL.toPrint(); //print list
    DLL.firstElem(); //print first element
    DLL.lastElem(); //print last element
    DLL.popFirst(); //pop first element
    DLL.toPrint(); //print list
    DLL.numOfElements(); //print number of elements
    DLL.popLast(); //pop last element
    DLL.toPrint(); //print list
    DLL.numOfElements(); //print number of elements
    DLL.firstElem(); //print first element
    DLL.lastElem(); //print last element 
    DLL.numOfElements(); //print number of elements
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popLast(); //pop last element
    DLL.popFirst(); //pop last element
    DLL.numOfElements(); //prints number of elements
    DLL.firstElem(); //prints first element
    DLL.lastElem(); //prints last element
    DLL.toPrint(); //print list
    DLL.addToEnd(9); //add to end
    DLL.addToFront(8); //add to front
    DLL.toPrint(); //print list
    DLL.popFirst(); //pop first element
    DLL.toPrint(); //print list
    DLL.popFirst(); //pop first element
    DLL.popFirst(); //pop first element
    DLL.popFirst(); //pop first element
    DLL.toPrint(); //print list

    //for char data type
    linkedList<char> DLLchar;
    DLLchar.addToFront ('a'); //add to front
    DLLchar.toPrint(); //print list
    DLLchar.numOfElements(); //print number of elements
    DLLchar.addToEnd ('b'); //add to end
    DLLchar.toPrint(); //print list
    DLLchar.addToFront ('c'); //add to front
    DLLchar.toPrint(); //print list
    DLLchar.addToFront ('d'); //add to front
    DLLchar.toPrint(); //print list
    DLLchar.addToEnd ('e'); //add to end
    DLLchar.toPrint(); //print list
    DLLchar.addToEnd ('f'); //add to end
    DLLchar.toPrint(); //print list
    DLLchar.firstElem(); //print first element
    DLLchar.lastElem(); //print last element
    DLLchar.popFirst(); //pop first element
    DLLchar.toPrint(); //print list
    DLLchar.numOfElements(); //print number of elements
    DLLchar.popLast(); //pop last element
    DLLchar.toPrint(); //print list
    DLLchar.numOfElements(); //print number of elements
    DLLchar.firstElem(); //print first element
    DLLchar.lastElem(); //print last element 
    DLLchar.numOfElements(); //print number of elements
    DLLchar.popLast(); //pop last element
    DLLchar.toPrint(); //print list
    DLLchar.popFirst(); //pop first element
    DLLchar.toPrint(); //print list
    DLLchar.numOfElements(); //print number of elements
    return 0;
}

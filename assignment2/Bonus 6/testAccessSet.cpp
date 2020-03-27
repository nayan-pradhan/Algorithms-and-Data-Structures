/* 
    CH-231-A
    a2 p6 Bonus cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <set>
#include "Access.h"
using namespace std;

int main() {
    Access object; //object
    object.activate(1234); //activates code 
    object.activate(9999); //activates code
    object.activate(9876); //activates code
    userInput(object); //gets user input and deactivates correct active code
    object.deactivate(9999); //deactivates code
    object.activate(1111); //deactivates code
    userInput(object); //gets user input and deactivates correct active code
    return 0;
}


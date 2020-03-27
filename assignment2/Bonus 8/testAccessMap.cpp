/* 
    CH-231-A
    a2 p8 Bonus cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <map>
using namespace std;
#include "Access.h"

int main() {
    Access object; //object
    object.activate(1234, 1); //activates code and sets level
    object.activate(9999, 5); //activates code and sets level
    object.activate(9876, 9); //activates code and sets level
    userInput(object, 5); //gets user input and deactivates correct active code
    //userInput also supplies the access level of door
    object.activate(9999, 8); //activates code and sets level
    object.activate(1111, 7); //activates code and sets level
    userInput(object, 7); //gets user input and deactivates correct active code
    //userInput also supplies the access level of door
    return 0;
}
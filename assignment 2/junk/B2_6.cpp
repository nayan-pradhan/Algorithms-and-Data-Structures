/* 
    CH-231-A
    a2 p6 Bonus cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <set>
using namespace std;
//class
class Access {
    public:
        void activate (unsigned int code); //activate method
        void deactivate (unsigned int code); //deactivate method
        bool isactive (unsigned int code) const; //isactive method
    private:
        set<unsigned int>activeCodes; //set of active codes
};
//method that activates the code enterd
void Access::activate (unsigned int code) { 
    activeCodes.insert(code);
}
//method that deactivates the code entered
void Access::deactivate (unsigned int code) {
    //checks if the code exists in set or not
    if (activeCodes.find(code) != activeCodes.end()) { //if exists
        auto pos = activeCodes.find(code); //pos stores the position of code
        activeCodes.erase(pos); //erases that pos, ie. code
    }
    //if code is not in set, nothing is done
}
//mehtod that checks whether entered code is active or not
bool Access::isactive (unsigned int code) const {
    if (activeCodes.find(code) != activeCodes.end()) { //if found
        cout << "Door opened successfully!" << endl;
        return true;
    }
    else { //if not found
        cout << "Access Denied! Door not opened!" << endl;
        return false;
    }
}
//function that gets user input and deactivates correct active code
void userInput(Access& object) { //passing address of object
    unsigned int x; //code that user inputs
    while (1) { //endless while loop
        cout << "Enter access code: ";
        cin >> x; //user code input
        if (object.isactive(x) == true) { //if bool function is active return true
            object.deactivate(x); //deactive the code (according to question)
            break; //breaks loop
        }
        //if flase, loop continues to ask for access code
    }
}

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


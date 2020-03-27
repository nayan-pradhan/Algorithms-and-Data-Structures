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

//class
class Access {
    public:
        void activate (unsigned int code, unsigned int level);//activate method
        void deactivate (unsigned int code); //deactivate method
        bool isactive (unsigned int code, unsigned int level) const;
        //isactive method
    private:
        set<unsigned int>activeCodes; 
        //set of active codes as active codes should not repeat
        map<unsigned int, unsigned int>codeAndLevel; 
        //map storing code and access level as key and value
};

//my function that takes user input where level is passed manually in main
void userInput(Access& object, unsigned int level); 

//method that activates the code enterd
void Access::activate (unsigned int code, unsigned int level) { 
    activeCodes.insert(code); //inserts code to set
    codeAndLevel[code] = level; //declares code as key and level as value
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
//mehtod that checks whether entered code is active or not as well as level
bool Access::isactive (unsigned int code, unsigned int level) const {
    if (activeCodes.find(code) != activeCodes.end()) { //if found
        map<unsigned int, unsigned int>::const_iterator itr; 
        //a const iterator is declared as my method states const
        for (itr = codeAndLevel.begin(); itr != codeAndLevel.end(); itr++) {
            //iterates through my map elements
            if ((*itr).first == code) { //if iterator key = my code
                if ((*itr).second >= level) { //check whether req level is met
                    cout << "Door opened successfully!" << endl; //if met
                    return true;
                }
                else { //if not met 
                    cout << "Access Level is low! Door not opened!" << endl;
                    return false;
                }
            }
        }
        cout << "Access Denied! Door not opened!" << endl;
        return false;
    }
    else { //if not found in first case
        cout << "Access Denied! Door not opened!" << endl;
        return false;
    }
}
//function that gets user input and level then deactivates correct active code
void userInput(Access& object, unsigned int level) { //passing address of object
    unsigned int x; //code that user inputs
    while (1) { //endless while loop
        cout << "Enter access code: ";
        cin >> x; //user code input
        if (object.isactive(x, level) == true) { //if bool function is active return true
            object.deactivate(x); //deactive the code (according to question)
            break; //breaks loop
        }
        //if flase, loop continues to ask for access code
    }
}

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
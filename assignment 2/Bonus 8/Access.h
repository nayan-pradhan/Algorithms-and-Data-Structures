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

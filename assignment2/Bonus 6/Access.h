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

void userInput(Access& object);
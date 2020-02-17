/* 
    CH-231-A
    a2 p3 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <deque>
//class WindGauge
class WindGauge {
    public:
        WindGauge (int period = 12); // constructor with default size 12
        void currentWindSpeed(int speed); //method to put speed in deque
        int highest() const; //gets highest wind speed
        int lowest() const; //gets lowest wind speed
        int average() const; //gets average wind speed
        void dump(WindGauge object) const; //dump method
    private:
        std::deque<int> DequeList; //deque
        int size;
};
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
        WindGauge (int period = 12); // constructor
        void currentWindSpeed(int speed); //method to put speed in deque
        int highest() const; //gets highest wind speed
        int lowest() const; //gets lowest wind speed
        int average() const; //gets average wind speed
        void dump(WindGauge object) const; //dump method
    private:
        std::deque<int> DequeList; //deque
};

WindGauge::WindGauge (int period) {
    period = 12;
}
//adds current wind speed in deque
void WindGauge::currentWindSpeed (int speed) {
    if (DequeList.size() == 12) { //if list is full
        DequeList.pop_front(); //delete the first element
    } //then
    DequeList.push_back(speed); //add element to back of list
}
//returns highest speed
int WindGauge::highest() const {
    int max = DequeList[0]; //initializing to first elem
    for (int i = 0; i < DequeList.size(); i++) { //loop through deque
        if (DequeList[i] > max) { //if any elem in deque is greater than max
            max = DequeList[i]; //max = that elem
        }
    }
    return max;
}

//returns lowest speed
int WindGauge::lowest() const {
    int min = DequeList[0]; //initializing to first elem
    for (int i = 0; i < DequeList.size(); i++) { //loop through deque
        if (DequeList[i] < min) { //if any elem in deque is smaller than max
            min = DequeList[i]; //min = that elem
        }
    }
    return min;
}

//returns average speed
int WindGauge::average() const {
    int sum = 0; //initializing sum to 0
    for (int i = 0; i < DequeList.size(); i++) { //loop going through deque
        sum += DequeList[i]; //sum of all elem
    }
    return (sum / (DequeList.size())); // return avg
}

//dump mehtod
void WindGauge::dump(WindGauge object) const {
    std::cout << "Highest: " << object.highest(); //returns highest
    std::cout << std::endl;
    std::cout << "Lowest: " << object.lowest(); //returns lowest
    std::cout << std::endl;
    std::cout << "Average: " << object.average(); //returns average
    std::cout << std::endl;
}

int main() {
    WindGauge object; //declaring object
    object.currentWindSpeed(15); //add current wind speed
    object.currentWindSpeed(16);
    object.currentWindSpeed(12);
    object.currentWindSpeed(15);
    object.currentWindSpeed(15);
    object.dump(object); //dump method called
    object.currentWindSpeed(16); //add current wind speed
    object.currentWindSpeed(17);
    object.currentWindSpeed(16);
    object.currentWindSpeed(16);
    object.currentWindSpeed(20);
    object.currentWindSpeed(17);
    object.currentWindSpeed(16); //after 12 elem, first elem gets deleted
    object.currentWindSpeed(15);
    object.currentWindSpeed(16);
    object.currentWindSpeed(20);
    object.dump(object); //dump method called
    return 0;
}
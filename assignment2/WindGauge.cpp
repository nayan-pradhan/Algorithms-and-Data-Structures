/* 
    CH-231-A
    a2 p3 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <deque>
#include "WindGauge.h"

//to initialize my list
WindGauge::WindGauge (int period) { //gets period if user inputs, else def val
    size = period; 
    DequeList.clear(); //empties list just to initialize
}
//adds current wind speed in deque
void WindGauge::currentWindSpeed (int speed) {
    if (DequeList.size() == size) { //if list is full
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
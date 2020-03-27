/* 
    CH-231-A
    a2 p3 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <deque>
#include "WindGauge.h"
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
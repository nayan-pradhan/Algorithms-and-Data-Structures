/* 
    CH-231-A
    a2 p4 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector>

//function that prints my vector using an interator
void printVector (std::vector<int> V) {
    std::vector<int>::iterator itr; //declaring vector iterator
    for (itr = V.begin(); itr != V.end(); itr++) { //loop through vector elem
        if (itr == V.end()-1) {  //if last element fo vector
            std::cout << *itr; //print without space
        }
        else { //else
            std::cout << *itr << " "; //print with space
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myVector; //declaring vector 
    for (int i = 0; i < 30; i++) { //adding elem 1 to 30 in vector list
        myVector.push_back(i+1); //pushing beack i+1 because i is from 0 to 29
    }
    // printVector(myVector);
    myVector.push_back(5); //pushing back 5
    std::reverse(myVector.begin(), myVector.end()); //reversing vector
    printVector(myVector); //passing myVector to print function I made
    std::replace(myVector.begin(), myVector.end(), 5, 129); //replacing
    printVector(myVector); //passing myVector to print function I made
    return 0;
}
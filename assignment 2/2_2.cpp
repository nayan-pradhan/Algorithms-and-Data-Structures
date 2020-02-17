/* 
    CH-231-A
    a2 p2 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque <float> A; //deque of type float A
    float x; //element
     
    while (1) { //endless while loop
        cout << "Enter float: ";
        cin >> x;
        if (x == 0) { //if x=0, stops taking val
            break;
        }
        else {
            if (x > 0) { //if positive
                A.push_back(x); //add elem to end of deque
            }
            else { //if negative
                A.push_front(x); //add elem to front of deque
            }
        }
    }
    for (int i = 0; i < A.size(); i++) { //print deque
        cout << A[i] << " ";
    }
    cout << endl; //empty line
    
    deque <float>::iterator itr; //iterator
    for (itr = A.begin(); itr != A.end(); itr++) { //loop going through deque
        if (*itr > 0) { // loop breaks when val of itr is positive
            break;
        } //this loops changes the value of itr and points it to first pos elem 
    }
    A.insert(itr, 0); //inserts 0 to middle of deque
    
    for (int i = 0; i < A.size(); i++) { //print using semicolon
        if (i == A.size()-1) { //last elem
            cout << A[i];
        }
        else { //other elem
            cout << A[i] << ";";
        }
    }
    cout << endl;
    return 0;
}
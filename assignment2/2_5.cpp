/* 
    CH-231-A
    a2 p5 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <set>
#include <time.h>
using namespace std;

int main() {
    //random number selector
    int x;
    srand (time(NULL)); //initializing rand num generator to time
    set<int> mySet; //declaring set
    while (mySet.size() < 6) { //max size of set is 6 elems
    //no dublicates as set does not contain dublicate data!
        x = rand() % 49 + 1;
        mySet.insert(x); //insert rand num to set
    }
    set<int>::iterator itr; //iterator
    for (itr = mySet.begin(); itr != mySet.end(); itr++) { //goes through set
        cout << *itr << " "; //print
    }
    cout << endl;
    return 0;
}
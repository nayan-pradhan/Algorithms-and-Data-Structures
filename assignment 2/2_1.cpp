/* 
    CH-231-A
    a2 p1 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include "list"

using namespace std;

//overloading << operator to print element of linked list in std output
ostream &operator << (ostream &o, const list<int> &l) {
    for (auto const& i : l) {
        int counter = 0; //counter
        if (counter == l.size()) { //last elem
            cout << i;
            cout << endl;
        }
        else { //all but last elem
            cout << i << " ";
        }
    }
    cout << endl;
    return o;
}

//overloading << operator to print element of linked list in diff file
ostream &operator << (ofstream &o, const list<int> &l) {
    for (auto const& i : l) {
        int counter = 0; //counter
        if (counter == l.size()) { //last elem
            o << i;
            o << endl;
        }
        else { //all but last elem
            o << i << " ";
        }
    }
    o << endl;
    return o;
}

//function that prints the linked list through an iterator
void printByIterator (list<int>l) {
    list<int>::iterator itr; //iterator itr
    for (itr = l.begin(); itr != l.end(); itr++) { //loop going through list
        auto lastElem = l.end(); //lastElem of type auto = end of list
        advance (lastElem, -1); //iterator points to last elem
        if (itr == lastElem) { //for printing last elem
            cout << *itr;
        }
        else { //for printing other
            cout << *itr << ",";
        }
    }
    cout << endl;
}

int main() {
    list<int>A; //first list
    list<int>B; //second list
    int x; //list elem
    while (1) { //endless while loop
        cout << "Enter int: ";
        cin >> x; //input
        if (x <= 0) { //if x < 0, loop breaks
            break;
        } 
        else { //else 
            A.push_back(x); //adds x to back of list
            B.push_front(x); //adds x to front of list
        }
    }
    cout << A; //prints A on standard output
    
    ofstream out ("listB.txt"); //making output file
    if (!out.good()) { //checking whehter file is successfully made or not
        cout << "Error creating file(1) listB.txt" << endl;
        exit(-1);
    }
    cout << "Created file(1): listB.txt" << endl;//message to know file created
    out << B; //prints B on file listB.txt

    cout << endl; //empty line

    A.splice(A.end(), A, A.begin()); //move 1st elem to end
    B.splice(B.end(), B, B.begin()); //move 1st elem to end

    printByIterator(A); //print by iterator
    printByIterator(B); //print by iterator
    
    cout << endl; //empty line

    A.merge(B); //merge B into A
    A.sort(); //sort A
    cout << A; //output A in standard output
    return 0;
}
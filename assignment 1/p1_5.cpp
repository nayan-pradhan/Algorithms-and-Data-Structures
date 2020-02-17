/* 
    CH-231-A
    a1 p5 cpp 
    Nayan Man Singh Pradhan
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    string temp; //temporary temp for swapping values
    string str; 
    vector<string> vec; //declaring string vector
    while (1) { //endless while loop
        cout << "Enter string: ";
        getline (cin, str); 
        if (str != "END") { //if entered string is not "END"
            vec.push_back(str); //puts the string in the vector
        }
        else { //else
            break;
        }
    }
    if (vec.size() < 4) { 
        /*if vector size is smaller that 4 (starts count from 1), the
        2nd and 5th element cannot be swapped */
        cout << "The elements cannot be swapped!" << endl;
    }
    else {
        cout << "Swapping element 2 and 5" << endl;
        //swapping algorithm
        temp = vec[1];
        vec[1] = vec[4];
        vec[4] = temp;
    }
    //replacing last elem with given value
    vec.at(vec.size()-1) = "???";

    //printing with index operator
    for (int i = 0; i < vec.size(); i++) {
        //for last elem
        if (i == vec.size()-1) {
            cout << vec[i];
        }
        else {
            cout << vec[i] << ",";
        }
    }
    cout << endl;

    vector<string>::iterator itr1; //iterator1
    for (itr1 = vec.begin(); itr1 != vec.end(); itr1++) {
        if (itr1 == vec.end()-1){
            cout << *itr1;
        }
        else {
            cout << *itr1 << ";";
        }
    }    
    cout << endl;

    reverse(vec.begin(), vec.end()); //reverses the vector
    vector<string>::iterator itr2; //iterator2
    for (itr2 = vec.begin(); itr2 != vec.end(); itr2++) {
        if (itr2 == vec.end()-1) {
            cout << *itr2;
        }
        else {
            cout << *itr2 << " ";
        }
    }     
    cout << endl;  
    return 0;
}
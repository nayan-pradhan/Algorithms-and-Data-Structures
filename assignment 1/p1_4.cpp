/* 
    CH-231-A
    a1 p4 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector> 
using namespace std;

int main () {
    string str; //my sitring
    vector<string> vec; //declaring vector vec
    //endless while loop
    while (1) {
        cout << "Enter word: ";
        cin >> str; //reads one word per line
        if (str != "END") {
            vec.push_back(str);
        }
        //if "END" is entered, it stops reading
        else {
            break;
        }
    }
    //for printing using index operator
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    //for printing using iterator
    vector<string>::iterator itr;
    for (itr = vec.begin(); itr != vec.end(); itr++) {
        if (itr == vec.end()-1) {
            cout << *itr;
        }
        else {
            cout << *itr << ",";
        }
    }
    cout << "\n";
    return 0;
}
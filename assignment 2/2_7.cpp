/* 
    CH-231-A
    a2 p7 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

/* made a bool function that checks whether name is in my collection or 
not and prints the associated date of birth if it is. */
bool checkName (string enteredName, map<string,string> myContacts);

int main() {
    map<string, string> myContacts; //my map
    string buffer; //buffer to get lines
    string bufferName; //buffer to store name
    string bufferDOB; //buffer to store DOB
    string enteredName; //name entered by user
    ifstream in("data.txt"); //opens file
    if (!in.good()) { //checks whether file opened successfully or not
        cout << "Error opening file data.txt!" << endl;
        exit (-1);
    } 
    /* The question says the text file should contain the name followed by a
    corresponding birth date on different lines REPEATED FOR many persons. 
    Therefore, my file data.txt contains the name, a semicolon, and the
    birthday. */
    while (!in.eof()) { //while end of file is not reached
        getline (in, buffer); //gets the data of file line by line
        for (int i = 0; i < buffer.length(); i++) { //iterating through line
            if (buffer[i] == ':') { //if semicolon found
                bufferName = buffer.substr(0, i); //everything before : is name
                bufferDOB = buffer.substr(i+1, buffer.length());//after is DOB
                myContacts[bufferName] = bufferDOB; //linking key and value
            }
        }
    }
    cout << "Enter name: "; 
    getline (cin, enteredName); //gets user input
    if (checkName(enteredName, myContacts) == false) { //if function returns F
        cout << "Name not found!" << endl; //print name not found
    }
    //function prints the DOB if it finds the name and returns T
    return 0;
}

/* bool function that checks whether name is in my collection or 
not and prints the associated date of birth if it is. */
bool checkName (string enteredName, map<string,string> myContacts) {
    map<string, string>::iterator itr; //iterator
    for (itr = myContacts.begin(); itr != myContacts.end(); itr++) {
        //going through each element of map
        if (enteredName == (*itr).first) { //if entered name matches key
            cout << "Date of Birth: " << (*itr).second << endl; //print value
            return true; //return true
        }
    }
    return false; //else return false
}
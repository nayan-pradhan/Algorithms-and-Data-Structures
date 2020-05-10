#include <iostream>
#include <vector>
#include <algorithm>

void readString(std::vector<std::string> &myVector) {
    bool checker = true;
    while (checker == true) {
        std::string tempString;
        std::cin >> tempString;
        if (tempString != "END") {
            myVector.push_back(tempString);
        }
        else {
            checker = false;
        }
    }
}

void print(std::vector<std::string> myVector) {
    std::vector<std::string>::iterator itr;
    for (itr = myVector.begin(); itr != myVector.end(); itr++) {
        if (itr == myVector.end()-1) {
            std::cout << *itr << std::endl;
        }
        else 
            std::cout << *itr << ", ";
    }
}

bool swap56(std::vector<std::string> &myVector) {
    if (myVector.size() < 4) {
        return false;
    }
    else {
        std::string temp = myVector[1];
        myVector[1]=myVector[4];
        myVector[4]=temp;
        return true;
    }
}

void replaceLast(std::vector<std::string> &myVector) {
    std::vector<std::string>::iterator itr = myVector.end()-1;
    *itr = "???";
    return;
}

void reverse(std::vector<std::string> &myVector) {
    reverse(myVector.begin(), myVector.end());
}

int main() {
    std::vector<std::string> myVector;
    readString(myVector);
    print(myVector);
    swap56(myVector);
    print(myVector);
    replaceLast(myVector);
    print(myVector);
    reverse(myVector);
    print(myVector);
}
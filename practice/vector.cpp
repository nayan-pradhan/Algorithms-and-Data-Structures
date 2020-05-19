#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 5, 3, 4};
    myVector.push_back(123);
    myVector.pop_back();
    std::vector<int>::iterator itr;
    for (itr = myVector.begin(); itr != myVector.end(); itr++) {
        if (itr == myVector.end()-1)
            std::cout << *itr << std::endl;
        else {
            std::cout << *itr << " -> ";
        }
    }
    std::vector<int>::iterator itrEr = myVector.begin()+2;
    myVector.erase(itrEr);
    std::vector<int>::iterator ittr;
    for (ittr = myVector.begin(); ittr != myVector.end(); ittr++) {
        if (ittr == myVector.end()-1)
            std::cout << *ittr << std::endl;
        else {
            std::cout << *ittr << " -> ";
        }
    }
}
#include <iostream>
#include <set>
 
void print (std::set<int>mySet) {
    std::set<int>::iterator itr;
    for (itr = mySet.begin(); itr!= mySet.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> mySet = {1,2,3,4,5,6,7,8, 21, 23};
    mySet.insert(1);
    mySet.insert(9);
    mySet.insert(10);
    print(mySet);
    mySet.erase(21);
    print(mySet);
    mySet.erase(23);
    auto itr = mySet.find(8);
    mySet.erase(itr);
    print(mySet);
}
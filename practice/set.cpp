#include <iostream>
#include <set>

// void print (std::set<int>mySet) {
//     std::set<int>::iterator itr;
//     for (itr = mySet.begin(); itr!= mySet.end(); itr++) {
//         std::cout << *itr << " ";
//     }
//     std::cout << std::endl;
// }

// use of template class
template <class T>
void print (T mySet) {
    // simply use auto for iterator because in this way i dont have
    // to define container type OR the type of data stroed in the container
    for (auto itr = mySet.begin(); itr!= mySet.end(); itr++) {
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

    std::set<int>::iterator lowerBound, upperBound;
    lowerBound = mySet.lower_bound(2);
    upperBound = mySet.upper_bound(6);
    mySet.erase(lowerBound, upperBound);
    print (mySet);

    std::multiset<char> myMultiSet = {'n', 'a', 'y', 'a', 'n'};
    print(myMultiSet);
    std::multiset<char> mySecondMultiSet = {'p','r','a','d','h','a','n'};
    myMultiSet.swap(mySecondMultiSet);
    print (myMultiSet);
}
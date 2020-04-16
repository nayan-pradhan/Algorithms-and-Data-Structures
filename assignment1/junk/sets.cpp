#include <iostream>
#include <set>

template <class T>
void print(std::multiset<T> mySet) {
    std::set <int>::iterator itr = mySet.begin();
    while (itr != mySet.end()) {
        std::cout << *itr << " ";
        itr++;
    }
}

int main() {
    std::multiset <int> mySet;
    for (int i = 0; i < 100; i = i + 12) {
        mySet.insert(i);
    }
    mySet.insert(15);
    mySet.insert(20);
    mySet.insert(20);
    print(mySet);
}


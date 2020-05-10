#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <class T>
void print (T myVector) {
    for (auto i = myVector.begin() ; i < myVector.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    print (myVector);

    std::vector<int>::reverse_iterator itr = myVector.rbegin();
    for (; itr != myVector.rend(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    // std::cout << myVector.max_size()<<std::endl;
    // std::cout << myVector.capacity()<<std::endl;
    // myVector.shrink_to_fit();
    // std::cout << myVector.max_size()<<std::endl;
    // std::cout << myVector.capacity()<<std::endl;
    // std::cout << myVector.front();
    // std::cout << myVector.data();
    // std::cout << std::endl;
    // int myInts[] = {2,3,5,2,4,2};
    // myVector.assign(myInts, myInts+3);
    // print (myVector);
    // myVector.pop_back();
    // print(myVector);
    // std::vector<int>::iterator it = myVector.begin();
    // it = myVector.insert(it,89);
}
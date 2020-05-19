#include <iostream>
#include <list>

void print (std::list<int>myList) {
    std::list<int>::iterator itr;
    for (itr = myList.begin(); itr != myList.end(); itr++) {
        if (itr == prev(myList.end())) { 
            /*
            HERE WE CANNOT USE myList.end()-1 BECAUSE THE OPERATOR IS NOT OVERLOADED.
            WE INSTEAD USE prev(myList.end()) THAT IS PART OF THE C++11 LIBRARY 
            */
            std::cout << *itr << std::endl;
        }
        else {
            std::cout << *itr << " -> ";
        }
    }
}

int main() {
    std::list<int> myList = {1,2,3,4};
    print(myList);
    std::list<int>::iterator itr = myList.begin();
    myList.insert(itr,79); // INSERTS 79 IN BEGINING.
    //THE ITERATOR STILL POINTS TO THE FIRST ORIGINAL ELEMENT -> 1 -> THAT IS NOW IN POSTION 2
    print(myList);
    myList.push_front(69);
    myList.push_back(720);
    itr++;
    itr++;
    myList.insert(itr, 2, 99); // INSERTS 2 99s IN POSITION OF ITERATOR (SAME AS ABOVE)
    print(myList);
    myList.remove(79); // REMOVES ALL 79 FROM THE LIST
    print(myList);
    myList.unique(); // REMOVES ALL DUBLICATE VALUES AFTER THE FIRST VALUE
    print(myList);
    myList.sort();
    print(myList);

    std::list<int> mySecondList = {5,6,7,8};
    // mySecondList.merge(myList);
    // print(mySecondList);

    itr++;
    myList.splice(myList.begin(),mySecondList, itr);
    std::cout << "mylist:";
    print(myList);
    std::cout << "my second list:";
    print(mySecondList);
}
#include <iostream>
#include <map>

// template <class T>
// void printer (std::map<T, T> myMap) {
void printer (std::map<std::string, int> myMap) {
    std::map<std::string, int>::iterator itr = myMap.begin();
    while (itr != myMap.end()) {
        std::cout << (*itr).first << " -> " << (*itr).second;
        std::cout << std::endl;
        itr++;
    }
}

int main() {
    std::map<std::string, int> myMap;
    myMap["January"] = 31;
    myMap["Feburary"] = 28;
    // myMap["Feburary"] = 27;
    myMap["August"] = 31;
    printer(myMap);
}
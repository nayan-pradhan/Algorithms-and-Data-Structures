#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, char, std::string> myTuple {1, 1.2, 'a', "hello"};
    std::cout << std::get<0>(myTuple) << std::endl;
    std::cout << std::get<1>(myTuple) << std::endl;
    std::get<0>(myTuple) = std::get<0>(myTuple) + 100;
    std::cout << std::get<0>(myTuple) << std::endl;
    std::get<0>(myTuple) = 11213;
    
}
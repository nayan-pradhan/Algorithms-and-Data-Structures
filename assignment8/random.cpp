#include <iostream>
#include <vector>

// int main() {
//     std::vector<int> myVec;
//     for (int i = 0; i < 10; i++) {
//         myVec.push_back(i);
//     }
//     for (int i = 0; i < 10; i++) {
//         std::cout << myVec[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "Popping ";
//     myVec.pop_back();
//     std::cout << "Popping ";
//     myVec.pop_back();
//     std::cout << "Popping ";
//     myVec.pop_back();

//     std::cout << std::endl;

//     std::vector<int>::iterator itr;
//     for (itr = myVec.begin(); itr != myVec.end(); itr++) {
//         std::cout << *itr << " ";
//     }
// }

int main() {
    int x = 1;
    try {
        if (x == 1) {
            throw "he";
        }
    }
    catch (...) {
        std::cout << "caught" << std::endl;
        exit (1);
    }
}
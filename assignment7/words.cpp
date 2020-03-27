/* 
    CH-231-A
    a7.1d cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector>

void print (std::vector<std::string> arr);
int maxLength (std::vector<std::string> arr);
void sort (std::vector<std::string>arr, int len);

int main() {
    std::vector<std::string>arr = {"word", "category", "cat", "new", "word", "bear", "at", "work", "time"};
    print (arr);
    int mL = maxLength(arr);
    sort(arr, mL);
}

void sort (std::vector<std::string>arr, int len) {
    std::vector<std::string>auxArray[len][26];
    std::vector<std::string>::iterator itr;
    while (len >= 0) {
        for (itr = arr.begin(); itr != arr.end(); itr++) {
            for (int i = 97; i < 123; i++) {
                if ((char)i == (*itr)[len]) {
                    (auxArray[len])[i-97].push_back(*itr);
                }
            }
        }
        len--;
    }

    // int tempLen = 8;
    // while (tempLen >= 0) {
    //     for (int i = 0; i < 26; i++) {
    //         std::cout << i << ": ";
    //         print (auxArray[tempLen][i]);
    //     }
    //     tempLen--;
    // }
}



void print (std::vector<std::string>arr) {
    std::vector<std::string>::iterator itr = arr.begin();
    while (itr+1 != arr.end()) {
        std::cout << *itr << ", ";
        itr++;
    }
    if (itr+1 == arr.end()) {
        std::cout << *itr << std::endl;
    }
}

int maxLength (std::vector<std::string>arr) {
    int max = 0;
    std::vector<std::string>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++) {
        int tempMax = 0;
        for (int i = 0; ((*itr)[i]) != '\0'; i++) {
            tempMax++;
        }
        if (tempMax > max) {
            max = tempMax;
        }
    }
    return max;
}


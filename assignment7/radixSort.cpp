#include <iostream>
#include <vector>
#include <math.h>

void print(std::vector<int>arr);
void radixSort(std::vector<int>*arr);
int largestElem(std::vector<int>arr);
int digitAtSigFig(int elem, int s);
int radixSortHelper(std::vector<int>*arr, int n);

int main() {
    std::vector<int>arr = {578, 561, 212, 1234, 1432, 4563, 121};
    std::cout << "array before sorting: ";
    print(arr);
    radixSort(&arr);
    std::cout << "array after sorting: ";
    print(arr);
}

void print(std::vector<int>arr) {
    std::vector<int>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

int largestElem(std::vector<int>arr) {
    int max = arr[0];
    std::vector<int>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++) {
        if (*itr > max) {
            max = *itr;
        }
    }
    return max;
}

int digitAtSigFig(int elem, int s) {
    int power = pow (10, s-1);
    return ((elem/power)%10);
}

void radixSort(std::vector<int>*arr) {
    int sigFig = log10(largestElem((*arr)))+1; //number of sigFig in max elem
    // std::vector<int>auxVector[10];
    radixSortHelper (&(*arr), sigFig);
}

int radixSortHelper(std::vector<int>*arr, int sigFig) {
    std::vector<int>auxVec[10];

    if (sigFig == 0) {
        return 0;
    }

    // std::vector<int>auxVec[10];

    std::vector<int>::iterator itr1;
    for (itr1 = (*arr).begin(); itr1 != (*arr).end(); itr1++) {
        int digit = digitAtSigFig(*itr1, sigFig);
        for (int i = 0; i < 10; i++) {
            if (digit == i) {
                auxVec[i].push_back(*itr1);
                std::cout << i << ": "; //for testing
                print (auxVec[i]); //for testing
            }
        }
    }
    std::cout << "___________________________________________" << std::endl; //for testing
    std::vector<int>::iterator itr2;
    for (int j = 0; j < 10; j++) {
        for (itr2 = auxVec[j].begin(); itr2 != auxVec[j].end(); itr2++) {
            radixSortHelper(&auxVec[j], sigFig-1);
        }
    }
}
/* 
    CH-231-A
    a7.2a.i cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <math.h>

void print(std::vector<int>arr);
// void radixSort(std::vector<int>*arr);
void radixSort(std::vector<int>arr);
int largestElem(std::vector<int>arr);
int digitAtSigFig(int elem, int s);
// void radixSortHelper(std::vector<int>*arr, int n);
void countingSort(std::vector<int>arr);

int main() {
    std::vector<int>arr = {578, 561, 212, 1234, 1432, 4563, 121};
    std::cout << "array before sorting: ";
    print(arr);
    radixSort(arr);
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

void radixSort (std::vector<int>(arr)) {
    int sigFig = log10(largestElem(((arr))))+1;
    std::cout << "sigFig = " << sigFig << std::endl; //delete later
    std::vector<int>::iterator itr;

    std::vector<int>store[10];

    int count = 0;
    while (sigFig > count) {
        for (itr = arr.begin(); itr != arr.end(); itr++) {
            int dig = digitAtSigFig(*itr, sigFig-count);
            int j = 0;
            while (j < 10) {
                if (j == dig) {
                    store[j].push_back(*itr);
                }
                j++;
            }
        }
        count++;
    }
    // for (int w = 0; w < 4; w++) {
    //     for (int r = 0; r < 10; r++) {
    //         print (store[w][r]);
    //     }
    // }

        // //delete later from here
        int k = 0;
        while (k < 10) {
            std::cout << k << ": ";
            print (store[k]);
            k++;
        }
        // //till here

    // radixSort(store[0]);
    // for (int u = 0; u < 10; u++) {
    //     radixSort(store[u]);
    // }
}

void countingSort (std::vector<int>*seq) {
    int k = (*seq)[0];
    for (int i = 0; i < (*seq).size(); i++) {
        if (k < (*seq)[i]) {
            k = (*seq)[i];
        }
    }
    k++; //size should be one more

    int C[k]; //auxiliary storage
    int B[(*seq).size()]; //output 
    for (int i = 0; i < k; i++) {
        C[i] = 0; //initialize the auxiliary storage
    }
    for (int j = 0; j < (*seq).size(); j++) {
        C[(*seq)[j]] = C[(*seq)[j]] + 1; //records how many repetations of elem
    }
    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1]; //sum of repeatition till and including that elem
    }
    for (int j = (*seq).size()-1; j >= 0; j--) {
        B[C[(*seq)[j]]-1] = (*seq)[j]; 
        C[(*seq)[j]] = C[(*seq)[j]] - 1;
    }
} 


// void radixSort(std::vector<int>*arr) {
//     int sigFig = log10(largestElem((*arr)))+1; //number of sigFig in max elem
//     radixSortHelper (&(*arr), sigFig);
// }

// void radixSortHelper(std::vector<int>*arr, int sigFig) {
//     std::vector<int>auxVec[10];

//     std::vector<int>::iterator itr1;
//     for (itr1 = (*arr).begin(); itr1 != (*arr).end(); itr1++) {
//         int digit = digitAtSigFig(*itr1, sigFig);
//         for (int i = 0; i < 10; i++) {
//             if (digit == i) {
//                 auxVec[i].push_back(*itr1);
//             }
//         }
//     }
//     std::vector<int>::iterator itr2;
//     while (sigFig > 0) {
//         for (int j = 0; j < 10; j++) {
//             for (itr2 = auxVec[j].begin(); itr2 != auxVec[j].end(); itr2++) {
//                 radixSortHelper(&auxVec[j], sigFig);
//                 sigFig--;
//             }
//         }
//     }

//     int position = 0; //position of element
//     for (int i = 0; i < (*arr).size(); i++) {
//         for (int j = 0; j < auxVec[i].size(); j++) {
//             (*arr)[position] = (auxVec[i])[j]; 
//             position++; //next position
//             print(*arr);
//         }
//     }
// }
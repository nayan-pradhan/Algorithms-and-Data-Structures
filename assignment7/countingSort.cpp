/* 
    CH-231-A
    a7.1a cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>

//just a function that prints the array
void printer (int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 7; //max number of elements in our list
    int seq[] = {9, 1, 6, 7, 6, 2, 1}; //input

    std::cout << "Array before sorting: ";
    printer (seq, n); //print array before sorting

    //biggest element of list is our k
    int k = seq[0];
    for (int i = 0; i < n; i++) {
        if (k < seq[i]) {
            k = seq[i];
        }
    }
    k++; //size should be one more

    int C[k]; //auxiliary storage
    int B[n]; //output 
    for (int i = 0; i < k; i++) {
        C[i] = 0; //initialize the auxiliary storage
    }
    for (int j = 0; j < n; j++) {
        C[seq[j]] = C[seq[j]] + 1; //records how many repetations of elem
    }
    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1]; //sum of repeatition till and including that elem
    }
    for (int j = n-1; j >= 0; j--) {
        B[C[seq[j]]-1] = seq[j]; 
        C[seq[j]] = C[seq[j]] - 1;
    }
    std::cout << "Array after sorting: ";
    printer (B, n); //print the array after sorting
}
/* 
    CH-231-A
    a3 p2a, b, c cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/
 
#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>

void selectionSort(int arr[], int n); //implementation of selection sort
void swapElem(int *a, int *b); //function that swaps elements of array
// void printArr(int arr[], int n); //function that prints my array

int main() {
    int x; //range user inputs
    int interval; //interval
    std::cout << "Enter max range: ";
    std::cin >> x;
    std::cout << "Enter interval: ";
    std::cin >> interval;
    std::ofstream out ("data.txt");

    for (int n = 1; n <= x; n=n+interval) { //loop creating array of n elements
        int arr[n]; 
        out << n << " ";

        // random number generator
        srand (static_cast < unsigned int > (time(0))); //for rand num
        //generates n random numbers for array
        for (int i = 0; i < n; i++) {
            arr[i] = rand()%99;
        }
        //timer start
        auto startArr = std::chrono::high_resolution_clock::now();
        selectionSort(arr, n); //sorting
        auto stopArr = std::chrono::high_resolution_clock::now();
        //timer stop
        auto durationArray = std::chrono::duration_cast
            <std::chrono::microseconds>(stopArr-startArr);
        out << durationArray.count() << " "; //prints time in mili second

        //case A: case involving the most number of swaps
        int caseA[n]; //creating an aray
        caseA[0] = arr[n-1]; //first elem of caseA is last elem of sorted array
        for (int i = 1; i <= n; i++) {
            caseA[i] = arr[i-1]; //shifting the rest of the terms and copying
        }

        //same process for case A
        auto startCaseA = std::chrono::high_resolution_clock::now();
        selectionSort(caseA, n);
        auto stopCaseA = std::chrono::high_resolution_clock::now();
        auto durationCaseA = std::chrono::duration_cast
            <std::chrono::microseconds>(stopCaseA-startCaseA);
        out << durationCaseA.count() << " ";

        //caseB: case involving minimum number of swaps
        int caseB[n];//creating case B
        for (int i = 0; i < n; i++) {
            caseB[i] = arr[i]; //copying the sorted array into caseB array
        }

        //same process for case B
        auto startCaseB = std::chrono::high_resolution_clock::now();
        selectionSort(caseA, n);   
        auto stopCaseB = std::chrono::high_resolution_clock::now();
        auto durationCaseB = std::chrono::duration_cast
            <std::chrono::microseconds>(stopCaseB-startCaseB);
        out << durationCaseB.count() << "\n";
    }
    return 0;
}

void selectionSort(int arr[], int n) { //selection sort function
    int smallest_pos; //the smallest position 
    for (int i = 0; i < n; i++) { //first loop
        smallest_pos = i; //declare smallest position as i
        for (int j = i + 1; j < n; j++) { //second loop to compare elem with
            if (arr[smallest_pos] > arr[j]) { //if we find smaller element
                smallest_pos = j; //position of smallest element is j
            }
        }
        if (arr[i] != arr[smallest_pos]) {
            swapElem (&arr[i], &arr[smallest_pos]); //uses swap function 
        }
    }
}

void swapElem (int *a, int *b) { //function that swaps elements
    int temp; //temperary
    temp = *a; 
    *a = *b;
    *b = temp;
}

// void printArr (int arr[], int n) { //fumction that prints array
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << "\n";
// }
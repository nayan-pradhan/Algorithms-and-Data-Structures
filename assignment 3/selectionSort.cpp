/* 
    CH-231-A
    a3 p2a, b, c cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <time.h>

void selectionSort(int arr[], int n); //implementation of selection sort
void swapElem(int *a, int *b); //function that swaps elements of array
void printArr(int arr[], int n); //function that prints my array

int counter = 0; //global variable counter that countes the number of swaps

int main() {
    int n;
    std::cout << "Enter number of random integers in your array: ";
    std::cin >> n; //gets number of integers
    int *arr; //dynmaically creating an array of n elements
    arr = new int[n]; //dynamically allocating memory

    // random number generator
    srand (static_cast < unsigned int > (time(0))); //for rand num
    //generates n random numbers for array
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%99;
    }

    std::cout << std::endl;

    //prints array before sorting from my function
    std::cout << "Unsorted Random Array:" << std::endl;
    printArr(arr, n);
    //implements selection sort from my function
    selectionSort(arr, n);
    //prints array after sorting from my function
    std::cout << "Sorted Array after selection sort:" << std::endl;
    printArr(arr, n);
    std::cout << "Number of swaps: " << counter << std::endl;
    counter = 0; //resetting the counter as it is a global variable
    
    std::cout << std::endl;

    //case A: case involving the most number of swaps
    int *caseA; //dynamically creating caseA array
    caseA = new int[n]; //allocating memory
    caseA[0] = arr[n-1]; //first elem of caseA is the last elem of sorted array
    for (int i = 1; i <= n; i++) {
        caseA[i] = arr[i-1]; //shifting the rest of the terms and copying
    }
    //output
    std::cout << "Case A with maximum number of swaps: " << std::endl; 
    printArr(caseA, n);
    std::cout << "We place the last element of sorted array in the" << 
        " front of the new array and shift the remaining elem!" << std::endl;
    std::cout << "After selection sort: " << std::endl; 
    selectionSort(caseA, n);
    printArr(caseA, n);
    std::cout << "Number of swaps: " << counter << std::endl;
    std::cout << "Here, the number of swaps is always n-1 swaps!" << std::endl;
    std::cout << "In this case, n = " << n << ". Therefore, n-1 = " << n-1 << 
        ", which is equal to the number of swaps." << std::endl;
    counter = 0; //resetting the counter as it is a global variable
    std::cout << std::endl;

    //caseB: case involving minimum number of swaps
    int *caseB; //dynamically creating caseB array
    caseB = new int[n]; //dynamically allocating memory
    for (int i = 0; i < n; i++) {
        caseB[i] = arr[i]; //copying the sorted array into caseB array
    }
    //output
    std::cout << "Case B with minimum number of swaps: " << std::endl; 
    printArr(caseB, n);
    std::cout << "It is the sorted list!" << std::endl;
    std::cout << "After selection sort: " << std::endl; 
    selectionSort(caseA, n);
    printArr(caseA, n);
    std::cout << "Number of swaps: " << counter << std::endl;
    std::cout << "Here, the number of swaps is always 0 swaps "<<
        "because the list is already sorted!" << std::endl;
    counter = 0; //resetting the counter as it is a global variable
    
    //delete for dynamically allocated memory
    delete []arr;
    delete []caseA;
    delete []caseB;
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
            counter++;
        }
    }
}

void swapElem (int *a, int *b) { //function that swaps elements
    int temp; //temperary
    temp = *a; 
    *a = *b;
    *b = temp;
}

void printArr (int arr[], int n) { //fumction that prints array
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
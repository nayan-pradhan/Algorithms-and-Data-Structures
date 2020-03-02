// CH-231-A
// a4 
// Nayan Man Singh Pradhan 
// n.pradhan@jacobs-university.de

#include <iostream>
#include <time.h>
#include <chrono>

void print (int *arr, int size);
void insertionSort (int *arr, int left, int right);
void mergeSort (int *arr, int left, int right, int k);
void merge (int *arr, int left, int right, int mid);

int main () {
    int size;
    int k;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    std::cout << "Enter k: ";
    std::cin >> k;
    //just to check for k
    if (k > size || k < 0) {
        std::cout << "Invalid input of k!" << std::endl;
        exit (-1);
    }
    int arr[size];
    srand (static_cast < unsigned int > (time(0))); //for rand num
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%999;
    }

    std::cout << "Array without sorting: " << std::endl;
    print (arr, size); 

    //for time taken to execute mergeSort with randomly generated array
    auto startArr = std::chrono::high_resolution_clock::now();
    mergeSort (arr, 0, size-1, k);
    auto stopArr = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast  
        <std::chrono::microseconds>(stopArr-startArr);
    
    std::cout << std::endl;
    
    std::cout << "Array with sorting: " << std::endl;
    print (arr, size);
    std::cout << "Total time taken: " << duration.count() << 
        " milli seconds." << std::endl;
    return 0;
}

//function that prints array
void print (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 

//function that executes insertion sort
void insertionSort (int *arr, int left, int right) {
    int key;
    for (int x = left+1; x < right; x++) {
        key = arr[x];
        int y = x - 1;
        while (y >= left && arr[y] > key) {
            arr[y+1] = arr[y];
            y--;
        }
        arr[y+1] = key;
    }
}

//function for mergeSort
void mergeSort (int *arr, int left, int right, int k) {
    //if the size of array reaches k, it does insertion sort
    if ((right - left + 1) <= k) {
        insertionSort(arr, left, right+1);
    }
    else if ((right - left + 1) > k) {
        int mid;
        if (left < right) {
            mid = left + ((right - left)/2);
            mergeSort (arr, left, mid, k);
            mergeSort (arr, mid + 1, right, k);
            merge (arr, left, right, mid);
        }
    }
}

void merge (int *arr, int left, int right, int mid) {
    int Lsize = mid - left + 1;
    int Rsize = right - mid;
    int L[Lsize];
    int R[Rsize];
    for (int i = 0; i < Lsize; i++) {
        L[i] = arr[i+left];
    }
    for (int j = 0; j < Rsize; j++) {
        R[j] = arr[mid + j + 1];
    }
    int a = 0;
    int b = 0; 
    int c = left;
    while (a < Lsize && b < Rsize) {
        if (L[a] < R[b]) {
            arr[c] = L[a];
            a++;
        }
        else {
            arr[c] = R[b];
            b++;
        }
        c++;
    }
    while (a < Lsize) {
        arr[c] = L[a];
        a++;
        c++;
    }
    while (b < Rsize) {
        arr[c] = R[b];
        b++;
        c++;
    }
}


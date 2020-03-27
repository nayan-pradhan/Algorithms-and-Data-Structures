// CH-231-A
// a4 
// Nayan Man Singh Pradhan 
// n.pradhan@jacobs-university.de

#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
#include <algorithm>

void print (int *arr, int size);
void insertionSort (int *arr, int left, int right);
void mergeSort (int *arr, int left, int right, int k);
void merge (int *arr, int left, int right, int mid);

int main () {
    int size;
    int k;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    std::ofstream output ("data.txt");
    std::cout << "File data.txt created to store values!" << std::endl;
    int avgRepeat = 50;
    int arr[avgRepeat][size];

    srand (static_cast < unsigned int > (time(0))); //for rand num
    for(int count = 0; count < avgRepeat; count++) {
        for (int i = 0; i < size; i++) {
            arr[count][i] = rand()%999;
        }
    }

    int bestCase[size];
    for (int i = 0; i < size; i++) {
        bestCase[i] = i;
    }

    int worstCase[size];
    for (int i = 0; i < size; i++) {
        worstCase[size-i-1] = bestCase[i];
    }

    for (k = 1; k <= size; k++) {
        output << k << " ";
        long timeSum = 0;
        for(int count = 0; count < avgRepeat; count++) {
            auto startArr = std::chrono::high_resolution_clock::now();
            mergeSort (arr[count], 0, size-1, k);
            auto stopArr = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast  
                <std::chrono::nanoseconds>(stopArr-startArr);
            timeSum += duration.count();
        }
        output << timeSum/avgRepeat << " ";
        auto startBest = std::chrono::high_resolution_clock::now();
        mergeSort (bestCase, 0, size-1, k);
        auto stopBest = std::chrono::high_resolution_clock::now();
        auto bestDuration = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopBest-startBest);
        output << bestDuration.count() << " ";

        auto startWorst = std::chrono::high_resolution_clock::now();
        mergeSort (worstCase, 0, size-1, k);
        auto stopWorst = std::chrono::high_resolution_clock::now();
        auto worstDuration = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopWorst-startWorst);
        output << worstDuration.count() << std::endl;
    }
    output.close();
    return 0;
}

void print (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 

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

void mergeSort (int *arr, int left, int right, int k) {
    if ((right - left + 1) <= k) {
        //std::cout << "insertion sort" << std::endl;
        insertionSort(arr, left, right + 1);
    }
    else if ((right - left + 1) > k) {
        //std::cout << "merge sort" << std::endl;
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
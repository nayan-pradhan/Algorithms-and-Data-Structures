#include <iostream>
#include <time.h>

void print (int *arr, int size);
void insertionSort (int *arr, int size);
void mergeSort (int *arr, int left, int right, int k);
void merge (int *arr, int left, int right, int mid);

int main () {
    int k;
    std::cout << "Enter k: ";
    std::cin >> k;
    int size = 10;
    if (k > size) {
        std::cout << "Invalid input of k!" << std::endl;
        exit (-1);
    }
    int arr[size];
    srand (static_cast < unsigned int > (time(0))); //for rand num
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%99;
    }
    std::cout << "Array without sorting: " << std::endl;
    print (arr, size); 

    mergeSort (arr, 0, size-1, k);

    std::cout << "Array with sorting: " << std::endl;
    print (arr, size);
    return 0;
}

void print (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
} 

void insertionSort (int *arr, int size) {
    int key;
    for (int x = 1; x < size; x++) {
        key = arr[x];
        int y = x - 1;
        while (y >= 0 && arr[y] > key) {
            arr[y+1] = arr[y];
            y--;
        }
        arr[y+1] = key;
    }
}

void mergeSort (int *arr, int left, int right, int k) {
    if ((right - left + 1) <= k) {
        insertionSort(arr, right + 1);
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


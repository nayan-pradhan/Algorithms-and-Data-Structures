#include <iostream>
#include <time.h>

void print (int *arr, int size);
void insertionSort (int *arr, int size);
void mergeSort (int *arr, int left, int right, int k);
void merge (int *arr, int left, int right, int mid);

int mergeCount;
int insertionCount;

int main () {
    mergeCount = 0;
    insertionCount = 0;
    int size;
    int k;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    int arr[size];

    for (int u = 0; u < size; u++) {
        std::cout << "Elem " << u+1 << ": ";
        std::cin >> arr[u];
    }

    std::cout << "Array without sorting: " << std::endl;
    print (arr, size); 
    
    for (k = 0; k <= size; k++) {
        mergeSort (arr, 0, size-1, k);

        std::cout << "Array with sorting: " << std::endl;
        print (arr, size);
        std::cout << "k = " << k << std::endl;
        std::cout << "Insertion = " << insertionCount << std::endl;
        std::cout << "Merge = " << mergeCount << std::endl;
        std::cout << "Total = " << insertionCount + mergeCount << std::endl;
        mergeCount = 0;
        insertionCount = 0;
    }
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
            insertionCount++;
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
        mergeCount++;
    }
    while (a < Lsize) {
        arr[c] = L[a];
        a++;
        c++;
        mergeCount++;
    }
    while (b < Rsize) {
        arr[c] = R[b];
        b++;
        c++;
        mergeCount++;
    }
}
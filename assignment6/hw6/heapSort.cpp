#include <iostream>
#include <time.h>
#include <vector>
#include <math.h>

void swapper (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printer (int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int left (int i) {return 2*i + 1;}
int right (int i) {return (2*i + 2);}

void maxHeapify (int *arr, int i, int n, int heapSize) {
    int largest = i;
    int l = left(i);
    int r = right(i);
    if (l < heapSize && arr[l] > arr[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r < heapSize && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swapper (&arr[i], &arr[largest]);
        maxHeapify(arr, largest, n, heapSize);
    } 
}

void buildMaxHeap (int *arr, int n, int heapSize) {
    heapSize = n;
    for (int i = n/2-1; i >= 0; i--) {
        maxHeapify(arr, i, n, heapSize);
    }
    for (int i = n-1; i >= 0; i--) {
        swapper (&arr[0], &arr[i]);
        maxHeapify(arr, i, n, heapSize);
    }
}

void heapSort (int *arr, int n, int heapSize) {
    buildMaxHeap(arr, n, heapSize);
    for (int i = n - 1; i >= 1; i--) {
        swapper (&arr[0], &arr[i]);
        heapSize--;
        maxHeapify(arr, 0, n, heapSize);
    }
}

int main() {
    int length;
    int heapSize = 0;
    std::cout << "Enter number of elements: ";
    std::cin >> length;

    if (length == 0) {
        std::cout << "Your array has no elements!" << std::endl;
        exit(0);
    }

    int arr[length];
    srand (static_cast < unsigned int > (time(0))); //for rand num
    for (int i = 0; i < length; i++) {
        arr[i] = (rand()%99);
    }

    std::cout << "Unsorted Array: ";
    printer (arr, length);
    heapSize = length;
    heapSort (arr, length, heapSize);
    std::cout << "Sorted Array: ";
    printer (arr, length);
}

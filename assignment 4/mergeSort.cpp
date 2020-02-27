#include <iostream>

void print (int *arr, int size);
void mergeSort (int *arr, int left, int right);
void merge (int *arr, int left, int right, int mid);

int main () {
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Elem " << i+1 << ": ";
        std::cin >> arr[i];
    }
    std::cout << "Array without sorting: " << std::endl;
    print (arr, size);

    mergeSort (arr, 0, size-1);

    std::cout << "Array after sorting: " << std::endl;
    print (arr, size);
    return 0;
}

void print (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void mergeSort (int *arr, int left, int right) {
    int mid;
    if (left < right) {
        mid = left + ((right - left) / 2) ;
        mergeSort (arr, left, mid);
        mergeSort (arr, mid+1, right);
        merge (arr, left, right, mid);
    }
}

void merge (int *arr, int left, int right, int mid) {
    int Lsize = mid - left + 1;
    int Rsize = right - mid;
    int L[Lsize];
    int R [Rsize];
    for (int i = 0; i < Lsize; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < Rsize; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int a = 0;
    int b = 0;
    int k = left;
    while (a < Lsize && b < Rsize) {
        if (L[a] < R[b]) {
            arr[k] = L[a];
            a++;
        }
        else {
            arr[k] = R[b];
            b++;
        }
        k++;
    }
    while (a < Lsize) {
        arr[k] = L[a];
        a++;
        k++;
    }
    while (b < Rsize) {
        arr[k] = R[b];
        b++;
        k++;
    }
}
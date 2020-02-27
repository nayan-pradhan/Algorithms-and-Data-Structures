#include <iostream>

void mergeSort (int arr[], int left, int right);
void merge (int arr[], int left, int right, int mid);
void print (int arr[], int size);

int main () {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Elem " << i+1 << ": ";
        std::cin >> arr[i];
    }
    std::cout << "Unsorted Array: ";
    print(arr, size);
    mergeSort(arr, 0, size-1);
    std::cout << "Sorted Array: ";
    print(arr, size);
    return 0;
}

void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort (arr, left, mid);
        mergeSort (arr, mid+1, right);
        merge (arr, left, right, mid);
    }
}

void merge (int arr[], int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int a = 0;
    int b = 0;
    int k = left;
    while (a < n1 && b < n2) {
        if (L[a] <= R[b]) {
            std::cout << L[a] << "<" << R[b]<< std::endl;
            arr[k] = L[a];
            a++;
        }
        else if (L[a] > R[b]) {
            std::cout << L[a] << ">" << R[b]<< std::endl;
            arr[k] = R[b];
            b++;
        }
        k++;
    }
    std::cout << " -------- " << std::endl;
    while (a < n1) {
                std::cout << "a<n1" << std::endl;
        arr[k] = R[a];
        k++;
        a++;
    }
    while (b < n2) {
                    std::cout <<"b<n2" <<std::endl;
        arr[k] = L[b];
        k++;
        b++;
    }

}

void print (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
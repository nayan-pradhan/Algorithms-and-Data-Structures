#include <iostream>
#include <time.h>

void print (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// void insertionSort (int *arr, int size) {
//     int key;
//     for (int a = 1; a < size; a++) {
//         key = arr[a];
//         int b = a - 1;
//         while (b >= 0 && arr[b] > key) {
//             arr[b+1] = arr[b];
//             b--;
//         }
//         arr[b+1] = key;
//     }
// }

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

int main() {
    int size;
    std::cout << "Enter size of list: ";
    std::cin >> size;
    int arr[size];
    srand (static_cast < unsigned int > (time(0)));
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%99;
    }
    std::cout << "Unsorted List: ";
    print (arr, size);
    insertionSort (arr, 0, size);
    std::cout << "Sorted List: ";
    print (arr, size);
    return 0;
}


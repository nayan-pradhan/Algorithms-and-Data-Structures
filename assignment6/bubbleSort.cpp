#include <iostream>

void printer (int *arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swapper (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (int *arr, int n) {
    for (int j = 0; j < n-1; j++) {
        for (int i = 0 ; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                swapper (&arr[i], &arr[i+1]);
            }
        }
    }
}

int main() {
    int n = 100;
    int bestCase[n];
    for (int i = 0; i < n; i++) {
        bestCase[i] = i;
    }
    std::cout << "Best Case:" << std::endl;
    printer(bestCase, n);

    int worstCase[n];
    for (int i = 99; i >= 0; i--) {
        worstCase[99-i] = i;
    }
    std::cout << "Worst Case:" << std::endl;
    printer(worstCase, n);
    
    int avgCase[n];
    srand (static_cast < unsigned int > (time(0))); //for rand num
    for (int i = 0; i < n; i++) {
        avgCase[i] = rand()%99;
    }
    std::cout << "Average Case:" << std::endl;
    printer(avgCase, n);

    bubbleSort(bestCase, n);
    bubbleSort(worstCase, n);
    bubbleSort(avgCase, n);

    std::cout << "After Sorting: " << std::endl; 

    std::cout << "Best Case:" << std::endl;
    printer(bestCase, n);
    std::cout << "Worst Case:" << std::endl;
    printer(worstCase, n);
    std::cout << "Average Case:" << std::endl;
    printer(avgCase, n);

    return 0;
}

#include <iostream>
#include <math.h>

int naiveRecursive (int n);
int bottomUp (int n);
int closedForm (int n);
int matrixRep (int n);

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Naive Recursive Method: ";
    std::cout << naiveRecursive (n);
    std::cout << std::endl;

    std::cout << "Bottom Up Method: ";
    std::cout << bottomUp (n);
    std::cout << std::endl;

    std::cout << "Closed Form: ";
    std::cout << closedForm (n);
    std::cout << std::endl;

    std::cout << "Matrix Representation: ";
    std::cout << matrixRep (n);
    std::cout << std::endl;
}

int naiveRecursive (int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return naiveRecursive (n-1) + naiveRecursive (n-2);
    }
}

int bottomUp (int n) {
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    arr[n] = 0;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int closedForm (int n) {
    double pos = ((1 + sqrt(5))/2);
    double neg = ((1 - sqrt(5)))/2;
    return ((pow(pos, n)- pow(neg, n)) / sqrt(5));
}
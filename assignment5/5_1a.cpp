/* 
    CH-231-A
    a5a 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <math.h>

//functions
int naiveRecursive (int n);
int bottomUp (int n);
int closedForm (int n);
void matrixRep (int n);
void matrixPower (int matrix[2][2], int n);
void matrixMultiply (int matrixA[2][2], int matrixB[2][2]);

int main() {
    int n;
    std::cout << "Enter n: "; //user input
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
    matrixRep (n);
    std::cout << std::endl;
}

int naiveRecursive (int n) {
    if (n == 0 || n == 1) { //base conditions
        return n;
    }
    else { //recursive until base condition is met
        return naiveRecursive (n-1) + naiveRecursive (n-2);
    }
}

int bottomUp (int n) {
    if (n == 1) { //if n = 1 case
        return 1;
    }
    int arr[n]; //an array of n elem is created
    arr[0] = 0; //we know 0th term
    arr[1] = 1; //we know 1st term
    arr[n] = 0; //initializing last term to 0
    for (int i = 2; i <= n; i++) { //loop 
        arr[i] = arr[i-1] + arr[i-2]; //calculates fibonacii
    }
    return arr[n]; //returns fibonacci until the last n
}

int closedForm (int n) {
    double pos = ((1 + sqrt(5))/2); //for formula
    double neg = ((1 - sqrt(5)))/2; //for formula
    return ((pow(pos, n)- pow(neg, n)) / sqrt(5)); //returns fibonacci
}

void matrixRep (int n) {
    if (n == 0) {
        std::cout << 0;
    }
    else {
        int myMatrix[2][2] = {{1,1}, {1,0}};
        if (n % 2 == 0) {
            matrixPower (myMatrix, n/2);
            matrixMultiply (myMatrix, myMatrix);
        }
        else {
            int refMatrix[2][2] = {{1,1}, {1,0}};
            matrixPower (myMatrix, (n-1)/2);
            matrixMultiply (myMatrix, myMatrix);
            matrixMultiply (myMatrix, refMatrix);
        }
        if (myMatrix[0][1] == myMatrix[1][0]) {
            std::cout << myMatrix[0][1] << std::endl;
        }
        else { 
            std::cout << "Error!" << std::endl;
        }
    }
}

void matrixPower (int matrix[2][2], int n) {
    if (n > 1) {
        int refMatrix[2][2] = {{1,1}, {1,0}};
        for (int k = 2; k <= n; k++) {
            matrixMultiply (matrix, refMatrix);
        }
    }
}

void matrixMultiply (int matrixA[2][2], int matrixB[2][2]) {
    int a = ((matrixA[0][0]*matrixB[0][0]) + 
        (matrixA[0][1]*matrixB[1][0]));
    int b = ((matrixA[0][0]*matrixB[0][1]) + 
        (matrixA[0][1]*matrixB[1][1]));
    int c = ((matrixA[1][0]*matrixB[0][0]) + 
        (matrixA[1][1]*matrixB[1][0]));
    int d = ((matrixA[1][0]*matrixB[0][1]) + 
        (matrixA[1][1]*matrixB[1][1]));
    //assigning a b c d to respective parts of matrix
    matrixA[0][0] = a;
    matrixA[0][1] = b;
    matrixA[1][0] = c;
    matrixA[1][1] = d;
}

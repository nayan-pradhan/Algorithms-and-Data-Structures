/* 
    CH-231-A
    a5_1a cpp
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/ 

#include <iostream>
#include <math.h>

//functions
long long int naiveRecursive (int n);
long long int bottomUp (int n);
long long int closedForm (int n);
long long int matrixRep (int n);
void matrixPower (int matrix[2][2], int n);
void matrixMultiply (int matrixA[2][2], int matrixB[2][2]);
long double powerClosed (long double value, int n);

long double pos = ((1 + sqrt(5))/2); //for formula in closed Form (global)
long double neg = ((1 - sqrt(5)))/2; //for formula in closed From (global)

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
    std::cout << matrixRep (n);
    std::cout << std::endl;
}

long long int naiveRecursive (int n) {
    if (n == 0 || n == 1) { //base conditions
        return n;
    }
    else { //recursive until base condition is met
        return naiveRecursive (n-1) + naiveRecursive (n-2);
    }
}

long long int bottomUp (int n) {
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

long long closedForm (int n) {
    if (n == 1 || n == 0) { //base cases
        return n;
    }
    else { //formula
        return ((powerClosed(pos, n) - powerClosed(neg, n))/sqrt(5));
    }
}

long double powerClosed (long double value, int n) {
    if (n == 0) { //base case
        return 1;
    }
    else if (n % 2 == 0) { //even case recursive
        return (powerClosed(value, n/2) * powerClosed(value, n/2));
    }
    else { //odd case recursive
        return (value * (powerClosed(value, (n-1)/2)) * 
            (powerClosed(value, (n-1)/2)));
    }
}

long long int matrixRep (int n) { 
    if (n == 0 || n == 1) { //base cases
        return n;
    }
    else {
        int myMatrix[2][2] = {{1,1}, {1,0}}; //making my matrix
        if (n % 2 == 0) { //if even number n
            matrixPower (myMatrix, n/2); //power with n/2 
            matrixMultiply (myMatrix, myMatrix); //multiply the two parts
        }
        else { //if odd number n
            //a reference matrix because our matrix will get modified
            int refMatrix[2][2] = {{1,1}, {1,0}}; 
            matrixPower (myMatrix, (n-1)/2); //power with (n-1)/2
            matrixMultiply (myMatrix, myMatrix); //multiply with itself
            matrixMultiply (myMatrix, refMatrix); //multiply with ref matrix
        }
        if (myMatrix[0][1] == myMatrix[1][0]) { //just checking
           return myMatrix[0][1];
        }
        else { //if the check is incorrect
            std::cout << "Error!" << std::endl;
            return (-1);
        }
    }
}

void matrixPower (int matrix[2][2], int n) {
    if (n > 1) {
        int refMatrix[2][2] = {{1,1}, {1,0}}; //another reference matrix
        for (int k = 2; k <= n; k++) {
            //poiwer of n is multiplication of matrix with itself n times
            matrixMultiply (matrix, refMatrix);
        }
    }
}

void matrixMultiply (int matrixA[2][2], int matrixB[2][2]) {
    //just a function that multiplies two matrices
    int a = ((matrixA[0][0]*matrixB[0][0]) + 
        (matrixA[0][1]*matrixB[1][0]));
    int b = ((matrixA[0][0]*matrixB[0][1]) + 
        (matrixA[0][1]*matrixB[1][1]));
    int c = ((matrixA[1][0]*matrixB[0][0]) + 
        (matrixA[1][1]*matrixB[1][0]));
    int d = ((matrixA[1][0]*matrixB[0][1]) + 
        (matrixA[1][1]*matrixB[1][1]));
    //assigning a b c d to respective parts of matrix
    //if this is not done, matrix values changes during operation giving error
    matrixA[0][0] = a;
    matrixA[0][1] = b;
    matrixA[1][0] = c;
    matrixA[1][1] = d;
}

/* 
    CH-231-A
    a5
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include <chrono>
#include <fstream>

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
    int userInput;
    int userMaxTime;
    std::cout << "Enter n: ";
    std::cin >> userInput;
    std::cout << "Enter max time in seconds: ";
    std::cin >> userMaxTime;
    long long int maxTime = userMaxTime * 1e9;
    
    std::ofstream naive ("naive.txt");
    std::ofstream bottom ("bottom.txt");
    std::ofstream closed ("closed.txt");
    std::ofstream matrix ("matrix.txt");

    long long indexTimeBottom = 0;
    int nB=1;
    while (1) {
        bottom << nB << " ";
        auto startBottom = std::chrono::high_resolution_clock::now();
        closedForm (nB); 
        auto stopBottom = std::chrono::high_resolution_clock::now();
        auto durBottom = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopBottom - startBottom);
        bottom << durBottom.count() << std::endl;
        indexTimeBottom += durBottom.count();
        if (indexTimeBottom >= maxTime) {
            std::cout << "Bottom Up form stopped because max time reached!" << std::endl;
            break;
        }
        if (nB == userInput) {
            std::cout << "Bottom Up form stopped because max n reached!" << std::endl;
            break;
        }
        nB++;
    }

    auto indexTimeClosed = 0;
    int nC=1;
    while (1) {
        closed << nC << " ";
        auto startClosed = std::chrono::high_resolution_clock::now();
        closedForm (nC); 
        auto stopClosed = std::chrono::high_resolution_clock::now();
        auto durClosed = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopClosed - startClosed);
        closed << durClosed.count() << std::endl;
        indexTimeClosed += durClosed.count();
        if (indexTimeClosed >= maxTime) {
            std::cout << "Closed form stopped because max time reached!" << std::endl;
            break;
        }
        if (nC == userInput) {
            std::cout << "Closed form stopped because max n reached!" << std::endl;
            break;
        }
        nC++;
    }

    auto indexTimeMatrix = 0;
    int nM=1;
    while (1) {
        matrix << nM << " ";
        auto startMatrix = std::chrono::high_resolution_clock::now();
        closedForm (nM); 
        auto stopMatrix = std::chrono::high_resolution_clock::now();
        auto durMatrix = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopMatrix - startMatrix);
        matrix << durMatrix.count() << std::endl;
        indexTimeMatrix += durMatrix.count();
        if (indexTimeMatrix >= maxTime) {
            std::cout << "Closed form stopped because max time reached!" << std::endl;
            break;
        }
        if (nM == userInput) {
            std::cout << "Closed form stopped because max n reached!" << std::endl;
            break;
        }
        nM++;
    }

    auto indexTimeNaive = 0;
    int nN=1;
    while (1) {
        naive << nN << " ";
        auto startNaive = std::chrono::high_resolution_clock::now();
        naiveRecursive (nN); 
        auto stopNaive = std::chrono::high_resolution_clock::now();
        auto durNaive = std::chrono::duration_cast
            <std::chrono::nanoseconds>(stopNaive - startNaive);
        naive << durNaive.count() << std::endl;
        indexTimeNaive += durNaive.count();
                std::cout << "indexTimeNaive:" << indexTimeNaive << std::endl; //delete later
                std::cout << "durNaive.count():" << durNaive.count() << std::endl; //delete later
        if (indexTimeNaive >= maxTime) {
            std::cout << "Naive Recursive form stopped because max time reached!" << std::endl;
            break;
        }
        if (nN == userInput) {
            std::cout << "Naive Recursive form stopped because max n reached!" << std::endl;
            break;
        }
        nN++;
    }

    naive.close();
    bottom.close();
    closed.close();
    matrix.close();
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

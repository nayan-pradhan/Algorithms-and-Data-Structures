/* 
    CH-231-A
    a5a 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <math.h>
#include <chrono>
#include <fstream>

//functions
int naiveRecursive (int n);
int bottomUp (int n);
int closedForm (int n);
void matrixRep (int n);
void matrixPower (long long int matrix[2][2], int n);
void matrixMultiply (long long int matrixA[2][2], long long int matrixB[2][2]);

int main() {
    // int userInput;
    int maxTime;
    int n;
    // std::cout << "Enter n: ";
    // std::cin >> userInput;
    std::cout << "Enter max time in seconds: ";
    std::cin >> maxTime;
    std::ofstream output ("data.txt");
    std::cout << "file data.txt created successfully!" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    while (1) {
        std::cout << "Enter n: ";
        std::cin >> n;
            output << n << " ";
            auto startNaive = std::chrono::high_resolution_clock::now();
            naiveRecursive (n); 
            auto stopNaive = std::chrono::high_resolution_clock::now();
            auto durNaive = std::chrono::duration_cast
                <std::chrono::microseconds>(stopNaive - startNaive);
            output << durNaive.count() << " ";

            auto startBottom = std::chrono::high_resolution_clock::now();
            bottomUp (n);
            auto stopBottom = std::chrono::high_resolution_clock::now();
            auto durBottom = std::chrono::duration_cast
                <std::chrono::microseconds>(stopBottom - startBottom);
            output << durBottom.count() << " ";

            auto startClosed = std::chrono::high_resolution_clock::now();
            closedForm (n);
            auto stopClosed = std::chrono::high_resolution_clock::now();
            auto durClosed = std::chrono::duration_cast
                <std::chrono::microseconds>(stopClosed - startClosed);
            output << durClosed.count() << " ";

            auto startMatrix = std::chrono::high_resolution_clock::now();
            matrixRep (n);
            auto stopMatrix = std::chrono::high_resolution_clock::now();
            auto durMatrix = std::chrono::duration_cast
                <std::chrono::microseconds>(stopMatrix - startMatrix);
            output << durMatrix.count() << std::endl;

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast  
                <std::chrono::seconds>(stop-start);
            std::cout << "time = " << duration.count() << "s" << std::endl;

            // if (n == userInput) {
            //     std::cout << "Max n reached!" << std::endl;
            //     exit (0);
            // }
            if (duration.count() > maxTime) {
                std::cout << "Max time reached!" << std::endl;
                exit(0);
            }
    }
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
    if (n == 1) {
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
    if (n == 0) { //if n is 0, the fibonacci is 0
        std::cout << 0;
    }
    else {
        long long int myMatrix[2][2] = {{1,1}, {1,0}}; //making my matrix
        if (n % 2 == 0) { //if even number n
            matrixPower (myMatrix, n/2); //power with n/2 
            matrixMultiply (myMatrix, myMatrix); //multiply the two parts
        }
        else { //if odd number n
            //a reference matrix because our matrix will get modified
            long long int refMatrix[2][2] = {{1,1}, {1,0}}; 
            matrixPower (myMatrix, (n-1)/2); //power with (n-1)/2
            matrixMultiply (myMatrix, myMatrix); //multiply with itself
            matrixMultiply (myMatrix, refMatrix); //multiply with ref matrix
        }
    }
}

void matrixPower (long long int matrix[2][2], int n) {
    if (n > 1) {
        long long int refMatrix[2][2] = {{1,1}, {1,0}}; //another reference matrix
        for (long long int k = 2; k <= n; k++) {
            //poiwer of n is multiplication of matrix with itself n times
            matrixMultiply (matrix, refMatrix);
        }
    }
}

void matrixMultiply (long long int matrixA[2][2], long long int matrixB[2][2]) {
    //just a function that multiplies two matrices
    long long int a = ((matrixA[0][0]*matrixB[0][0]) + 
        (matrixA[0][1]*matrixB[1][0]));
    long long int b = ((matrixA[0][0]*matrixB[0][1]) + 
        (matrixA[0][1]*matrixB[1][1]));
    long long int c = ((matrixA[1][0]*matrixB[0][0]) + 
        (matrixA[1][1]*matrixB[1][0]));
    long long int d = ((matrixA[1][0]*matrixB[0][1]) + 
        (matrixA[1][1]*matrixB[1][1]));
    //assigning a b c d to respective parts of matrix
    //if this is not done, matrix values changes during operation giving error
    matrixA[0][0] = a;
    matrixA[0][1] = b;
    matrixA[1][0] = c;
    matrixA[1][1] = d;
}

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
int matrixPower (int **myMatrix, int n);
void delocateMatrix (int **myMatrix);

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
    int **myMatrix = new int*[2]; //dynamically creating a 2d array
    for (int i = 0 ; i < 2; i++) {
        myMatrix[i] = new int[2];
    }
    //myMatrix
    myMatrix[0][0] = 1;
    myMatrix[0][1] = 1;
    myMatrix[1][0] = 1;
    myMatrix[1][1] = 0;
    //passing to calculate power of matrix
    matrixPower (myMatrix, n);
    if (myMatrix[0][1] == myMatrix[1][0]) { //this should always be true
        std::cout << myMatrix [0][1] << std::endl;
    }
    else { //if not true, there is an error
        std::cout << "Error!" << std::endl;
    }
    delocateMatrix (myMatrix); //delocate allocated memory for matrix
}
    
int matrixPower (int **myMatrix, int n) {
    int refMatrix[2][2]; //a reference matrix to multiply myMatrix 
    refMatrix[0][0] = 1;
    refMatrix[0][1] = 1;
    refMatrix[1][0] = 1;
    refMatrix[1][1] = 0;
    if (n < 2) { //if n is 1
        return **myMatrix;
    }
    else { 
        //power is multyplying the matrix with itself n number of times
        for (int i = 2; i <= n; i++) {
            //using a b c d because value of myMatrix[][] changes
            int a = ((myMatrix[0][0]*refMatrix[0][0]) + 
                (myMatrix[0][1]*refMatrix[1][0]));
            int b = ((myMatrix[0][0]*refMatrix[0][1]) + 
                (myMatrix[0][1]*refMatrix[1][1]));
            int c = ((myMatrix[1][0]*refMatrix[0][0]) + 
                (myMatrix[1][1]*refMatrix[1][0]));
            int d = ((myMatrix[1][0]*refMatrix[0][1]) + 
                (myMatrix[1][1]*refMatrix[1][1]));
            //assigning a b c d to respective parts of matrix
            myMatrix[0][0] = a;
            myMatrix[0][1] = b;
            myMatrix[1][0] = c;
            myMatrix[1][1] = d;
        }
        return **myMatrix;
    }
}

void delocateMatrix (int **myMatrix) { //delocate memory of matrix
    // std::cout << "Matrix delocated from memory!" << std::endl; //message
    for (int i = 0; i < 2; i++) {
        delete [] myMatrix[i];
    }
    delete [] myMatrix;
}
/* 
    CH-231-A
    11.2 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <algorithm>

void getInput(std::vector<int>&input);
void print(std::vector<int>vector);
int max(int a, int b);
void maxTriangle(std::vector<int>&input);
 
// main function
int main() {
    std::vector<int>input; // input vector
    try { // range exception catcher
        getInput(input); // function that gets the input
        // input = {7,3,8,8,1,0,2,7,4,4,4,5,2,6,5};
        maxTriangle(input); // function that prints the solution
    } catch (const char* err) {
        std::cout << "exception: " << err << std::endl;
    }
}

// function that gets the input
void getInput(std::vector<int>&input) {
    /* 
        user has to enter the height of the tree, then
        each element of the tree followed by an enter
    */
    int n;
    std::cout << "Enter height of tree: ";
    std::cin >> n;
    // range
    if (n <= 1 || n > 100) {
        throw "Invalid Range";
    }
    for (int i = 0; i < (n*(n+1))/2; i++) { // formula
        int a;
        std::cin >> a;
        input.push_back(a);
    }
}

// printer function to check 
void print(std::vector<int>vector) {
    for (auto itr = vector.begin(); itr != vector.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

// compares two int values and returns the greater value
int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

// prints the soultion
void maxTriangle(std::vector<int>&input) {
    int m = input.size(); // for easier computation
    for (int n = m - 1; n > 0; n--) { // formula
        for (int k = (n*(n-1))/2; k < (n*(n+2))/2; k++) { // formula
            auto maximum = max(input[k+n], input[k+n+1]);
            input[k] += maximum;
        }
    }
    // input[0] will store the final solution derived from dynamic programming
    std::cout << input[0] << std::endl;
}   
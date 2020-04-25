#include <iostream>
#include <vector>
#include <algorithm>

void getInput(std::vector<int>&input);
void print(std::vector<int>vector);
int max(int a, int b);
void maxTriangle(std::vector<int>&input);

int main() {
    std::vector<int>input;
    // getInput(input);
    input = {7,3,8,8,1,0,2,7,4,4,4,5,2,6,5};
    maxTriangle(input);
}

void getInput(std::vector<int>&input) {
    int n;
    std::cout << "Enter height of tree: ";
    std::cin >> n;
    if (n <= 1 || n > 100) {
        throw "Invalid Range";
    }
    for (int i = 0; i < (n*(n+1))/2; i++) {
        int a;
        std::cin >> a;
        input.push_back(a);
    }
}

void print(std::vector<int>vector) {
    for (auto itr = vector.begin(); itr != vector.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

void maxTriangle(std::vector<int>&input) {
    int m = input.size();
    std::vector<int> modifiedVector;
    for(int i = 0; i < m; i++) {
        modifiedVector.push_back(input[i]);
    }
    for (int n = m - 1; n > 0; n--) {
        for (int k = (n*(n-1))/2; k < (n*(n+2))/2; k++) {
            auto maximum = max(modifiedVector[k+n], modifiedVector[k+n+1]);
            modifiedVector[k] += maximum;
        }
    }
    std::cout << modifiedVector[0] << std::endl;
}   
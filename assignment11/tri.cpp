#include <iostream>
#include <vector>

struct Node {
    int original;
    int modifiable;
    void insert(int og, int mod) {
        this->original=og;
        this->modifiable=mod;
    }
};

void getInput(std::vector<int>input);
void print(std::vector<int>vector);
int max(int a, int b);
std::vector<Node> convToNode(std::vector<int>input);
void maxTriangle(std::vector<Node>&input);
void printPath(std::vector<Node>vector);


int main() {
    std::vector<int>input;
    getInput(input);
    // input = {7,3,8,8,1,0,2,7,4,4,4,5,2,6,5};
    convToNode(input);
}

void getInput(std::vector<int>input) {
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

std::vector<Node> convToNode(std::vector<int>input) {
    std::vector<Node> myTriangle;
    Node myTempTri[input.size()];
    for (int i = 0; i < input.size(); i++) {
        myTempTri[i].insert(input[i],input[i]);
    }
    for (int i = 0; i < input.size(); i++) {
        myTriangle.push_back(myTempTri[i]);
    }
    maxTriangle(myTriangle);
    return myTriangle;
}

void printPath(std::vector<Node>vector) {
    for (auto itr = vector.begin(); itr != vector.end(); itr++) {
        std::cout << itr->original << " ";
    }
    std::cout << std::endl;
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

void maxTriangle(std::vector<Node>&input) {
    int m = input.size();
    for (int n = m - 1; n > 0; n--) {
        for (int k = (n*(n-1))/2; k < (n*(n+2))/2; k++) {
            auto maximum = max(input[k+n].modifiable, input[k+n+1].modifiable);
            input[k].modifiable += maximum;
        }
    }
    std::cout << input[0].modifiable << std::endl;
    printPath(input);
}   

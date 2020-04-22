/* 
    CH-231-A
    11.1 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include<iostream>
#include<vector>

void getInput(std::vector<int>&vector);
void print(std::vector<int>vector);
std::vector<int>LOS(std::vector<int>inputArray); 

int main() {
    std::vector<int>inputArray;
    getInput(inputArray);
    print(LOS(inputArray));
}

// gets the input from the user
void getInput(std::vector<int>&vector) {
    int n, input;
    std::cout << "Enter Size: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "elem " << i+1 << ": ";
        std::cin >> input;
        vector.push_back(input);
    }
}

// prints the vector
void print(std::vector<int>vector) {
    for(auto itr = vector.begin(); itr != vector.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

// returns the longest ordered subsequence using dynamic programming
std::vector<int>LOS(std::vector<int>inputArray) {
    std::vector<int>finalArray[inputArray.size()]; // a vector stroing solution
    finalArray[0].push_back(inputArray[0]); // first elem is the elem itself
    for (int i = 1; i < inputArray.size(); i++) {
        for (int j = 0; j < i; j++) {
            /* 
                inputArray[i]>inputArray[j]->the elem is in ascending order

                finalArray[j].size()+1>finalArray[i].size()->the solution
                sequence can be extended
            */
            if (inputArray[i] > inputArray[j] 
                && finalArray[j].size()+1 > finalArray[i].size()) {
                    finalArray[i] = finalArray[j];
            }
        }
        finalArray[i].push_back(inputArray[i]); // adding elem to solutiuon
    }
    // returning the vector with the longest (ordered) subsequence
    auto max = finalArray[0];
    for (int i = 0; i < inputArray.size(); i++) {
        if (finalArray[i].size() > max.size()) {
            max = finalArray[i];
        }
    }
    return max;
}
#include <iostream>
#include <vector>

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i]+nums[j] == target && i != j) {
                    std::cout << nums[i];
                                        std::cout << nums[j];
                    solution.push_back(i);
                    solution.push_back(j);
                    for (int k = 0; k < solution.size(); k++) {
                        std::cout << solution[k] << " ";
                    }
                    return solution;
                }
            }
        }
        throw -1;
    }

int main() {
    std::vector<int> myVec;
    myVec.push_back(3);
    myVec.push_back(2);
    myVec.push_back(4);
    twoSum(myVec, 6);
}
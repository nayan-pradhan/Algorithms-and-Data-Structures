/*
    Takes targetSum and an array of numbers as arguments.
    Returns boolean indicating whether or not it is possible to generate targetSum using numbers from array.
*/

#include <iostream>
#include <vector>
#include <map>

// compile with c++11
// g++ -std=c++11 -o canSum canSum.cpp
// ./canSum

class canSum {
    public:

        bool canSumResult(int t, std::vector<int> v) {
            std::map<int, bool> memo;
            return (helper(t, v, memo));
        }

        bool helper(int t, std::vector<int> v, std::map<int, bool>& memo) {

            auto it = memo.find(t);
            if (it != memo.end()) {
                return it->second;
            }

            if (t == 0) {return true;}
            if (t < 0) {return false;}

            for (int i : v) {
                int remainder = t - i;
                memo[t] = helper(remainder, v, memo);
                if (memo[t] == true) {
                    return true;
                }
            }

            memo[t] = false;
            return memo[t];
        }
};

int main() {
    canSum c;
    std::vector<int> v = {2,4,6,14};
    int target = 1600;
    std::cout << c.canSumResult(target, v) << std::endl;
}

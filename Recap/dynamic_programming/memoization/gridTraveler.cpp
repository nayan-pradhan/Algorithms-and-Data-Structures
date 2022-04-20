/*
    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
//     Not optimized
    
//     int uniquePaths(int m, int n) {
//         int result = 0;
//         result = helper(m, n);
//         return result;
//     }
    
//     int helper(int m, int n) {
//         if (m == 0 || n == 0) {
//             return 0;
//         }    
//         if (m == 1 && n == 1) {
//             return 1;
//         }
//         return helper(m-1, n) + helper(m, n-1);
//     }
    
//      Optimized
    
    int uniquePaths(int m, int n) {
        int result = 0;
        map<string, int> memo;
        result = helper(m, n, memo);
        return result;
    }
    
    int helper(int m, int n, map<string, int>& memo) {
        
        string keys = to_string(m)+","+to_string(n);
        
        map<string, int>::iterator it = memo.find(keys);
        
        if (it != memo.end()) {
            return it->second;
        }
        
        if (m == 0 || n == 0) {
            return 0;
        }    
        if (m == 1 && n == 1) {
            return 1;
        }
        memo[keys] = helper(m-1, n, memo) + helper(m, n-1, memo);
        return memo[keys];
    }
    
};

int main() {
    Solution e;
    std::cout << e.uniquePaths(23,12) << std::endl;
}
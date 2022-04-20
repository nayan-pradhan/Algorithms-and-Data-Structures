/*
    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
*/

#include <iostream>
#include <map>

class fibonacciClass {

    public:

        int n;

        fibonacciClass() {
            n = 0;
        }

        fibonacciClass(int x) {
            n = x;
        }

        int get_fibonacci() {
            int result = 0;
            std::map<int, int> memo;
            result = compute_fibonacci(n, memo);
            return result;
        }

        int compute_fibonacci(int n, std::map<int, int>& memo) {
            std::map<int, int>::iterator it = memo.find(n);
            if (it != memo.end()) {
                return (it->second);
            }
            if (n <= 2) {
                return 1;
            }
            memo[n] = compute_fibonacci(n-1, memo) + compute_fibonacci(n-2, memo);
            return memo[n];
        }

};

int main() {
    fibonacciClass num(40);
    std::cout << num.get_fibonacci() << std::endl;
}
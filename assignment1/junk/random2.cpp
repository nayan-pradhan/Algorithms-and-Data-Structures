#include <iostream>

    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        else if (n > 0) {
            double og = x;
            double temp = 1;
            for (int i = 0; i < n; i++) {
                temp = og * temp;
            }
            return temp;
        }
        else {
            double og = x;
            double temp = 1;
            int newRange = (-1) * n;
            for (int i = 0; i < newRange; i++) {
                temp = og * temp;
            }
            return (1/temp);
        }
    }

    int main() {
        std::cout <<myPow (2, -2);
    }
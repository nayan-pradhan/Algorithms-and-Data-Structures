#include <iostream>

template <class T>
T& multiplies (T sum, T x, T n) {
    for (int i = 0; i <= n; i++) {
        sum = sum + (x*i);
    }
    return sum;
}

int main() {
    int sum = 1;
    int x = 2;
    int n = 10;
    std::cout << multiplies(sum, x, n) << std::endl;
}
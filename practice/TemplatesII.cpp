#include <iostream>

template <class T>
void multiplies (T &sum, T x, T n) {
    for (int i = 0; i <= n; i++) {
        sum = sum + (x*i);
    }
}

int main() {
    int sum = 1;
    int x = 2;
    int n = 10;
    multiplies(sum, x, n);
    std::cout << sum << std::endl;
}
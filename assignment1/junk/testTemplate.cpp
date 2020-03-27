#include <iostream>
using namespace std;

template <class T>
T sum (T, T);

int main () {
    string a = "abcd";
    string b = "efgh";
    cout << sum (a, b) << endl;
}

template <class T>
T sum (T a, T b) {
    return a+b;
}
#include <iostream>
#include "vector"
using namespace std;

struct Vertex {
    float a, b, c;
};

ostream& operator<< (ostream& output, const Vertex& v) {
    output << v.a << ", " << v.b << ", " << v.c << endl;
    return output;
}

int main() {
    vector <int> verticeas
    vertex.push_front(2,5,6);
    return 0;
}
#include <iostream>

void print_array(int* array, int n, std::string name = "A") {
    std::cout << name << " : ";
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int get_max_num(int* array, int n) {
    int max = array[0];
    for (int i = 0; i < n; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

int main(int argc, char** argv) {
    // input
    int n = 0;
    std::cout << "Enter number of elements in array: ";
    std::cin >> n;
    int* A;
    A = new int[n];
    for (int i = 0; i < n; i++) {
        int temp = 0;
        std::cout << "A[" << i << "] : ";
        std::cin >> temp;
        A[i] = temp;
    }
    print_array(A, n);

    // max elem
    int max_num = 0;
    max_num = get_max_num(A, n);

    // counting sort

    // 1.
    int C[max_num];
    for (int i = 0; i < max_num; i++) {
        C[i] = 0;
    }
    print_array(C, max_num, "C");
    
    // 2.
    for (int j = 0; j < max_num; j++) {
        C[A[j]-1] = C[A[j]-1] + 1;
    }
    print_array(C, max_num, "C'");

    // 3.
    for (int i = 1; i < max_num; i++) {
        C[i] += C[i-1];
    }
    print_array(C, max_num, "C''");

    // 4.
    int* B;
    B = new int[n];
    for (int j = n-1; j > -1; j--) {
        print_array(B, n, "B");
        print_array(C, max_num, "C");
        B[C[A[j]-1]-1] = A[j];
        C[A[j]-1] -= 1;
    }
    print_array(B, n, "Result >> B");

    delete B;
    delete A;
}
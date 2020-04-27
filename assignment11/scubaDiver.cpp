#include <iostream>
#include <algorithm>

void scubaDiver(int t, int a, int n, int *oxy, int *nit, int *weight);

int main() {
    int c; // number of test cases
    std::cin >> c;
    try {
        for (int i = 0; i < c; i++) {
            int t, a, n; 
            // t->oxygen, a->nitrogen n-> number of cylinders
            std::cin >> t >> a;
            if ((t > 21 || t < 1) || (a > 79 || a < 1)) {
                throw "Out of Range!";
            }
            std::cin >> n;
            if (n < 1 || n > 1000) {
                throw "Out of Range";
            }

            int oxy[1000], nit[1000], weight[1000];
            for (int i = 0; i < n; i++) {
                std::cin >> oxy[i] >> nit[i] >> weight[i];
            }
            scubaDiver(t, a, n, oxy, nit, weight);
        }
    }
}

void scubaDiver(int t, int a, int n, int *oxy, int *nit, int *weight) {
    int solution[1000][22][80]; // 3D matrix for solution with maximum size

    // first we initialize the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            for (int k = 0; k <= a; k++) {
                solution[i][j][k] = __INT_MAX__;
                // initializing all the positions entered by the user to infinity
                if (k == 0 && j == 0) {
                    solution[i][j][k] = 0;
                    // initialzing the unused slots to 0
                }
            }
        }
    }

    for (int j = 0; j <= t; j++) {
        for (int k = 0; k <= a; k++) {
            if ((j <= oxy[0] && k <= nit[0]) && (j > 0 && k > 0)) {
                solution[0][j][k] = weight[0];
            }
        }
    }
}
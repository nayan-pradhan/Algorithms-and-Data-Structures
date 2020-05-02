/* 
    CH-231-A
    12.2 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>
#include <algorithm>
#include <climits>

void getInput(int &n, int &p, int &q, int **&adj_matrix);
int find_meetup_city(int **adj_matrix, int num_of_cities,
    int your_city, int friend_city);
void freeMemory(int n, int **&adj_matrix);

int main() {
    // n -> number of cities; p -> your city; q -> your friend's city
    int n = 0, p = 0, q = 0;
    std::cout << "Enter number of cities: ";
    std::cin >> n;
    if (n < 1) { // invalid number of cities
        std::cout << "No cities available" << std::endl;
        exit(-1);
    }
    // dynamically allocate memory for created array
    int **adj_matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adj_matrix[i] = new int[n];
    }
    // get the input
    getInput(n, p, q, adj_matrix);
    // run and print algorithm
    std::cout << "The optimal meeting point: " <<
        find_meetup_city(adj_matrix, n, p, q) << std::endl;
    // dellacote dynamically allocated memroy
    freeMemory(n, adj_matrix);
}

// get input
void getInput(int &n, int &p, int &q, int **&adj_matrix) {
    // set adjacent matrix through input
    std::cout << "Enter distance between the cities: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { // if same city, distance = 0
                std::cout << "Same city so distance ["<< i+1 
                << "][" << j+1 <<"] is 0" << std::endl;
                adj_matrix[i][j] = 0;
            }
            else {
                std::cout << "distance from city " << i+1 << " and city " 
                << j+1 <<" -> ";
                std::cout << "matrix[" << i+1 << "][" << j+1 <<"] : ";
                std::cin >> adj_matrix[i][j];
                if (adj_matrix[i][j] == -1) { // if cities are not connected
                    adj_matrix[i][j] = INT_MAX; // infinity
                }
            }
        }
    }
    std::cout << "Your city: ";
    std::cin >> p; // enter your city
    std::cout << "Friend's city: ";
    std::cin >> q; // enter your friend's city
}

// main solution
int find_meetup_city(int **adj_matrix, int n, int p, int q) {
    // Floyd Warshall Algorithm:
    // Gives us the shortest path between two cities for all cities
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (adj_matrix[j][k] > (adj_matrix[j][i] + adj_matrix[i][k])) {
                    // if (the path from i->j->k < path from i->k)
                    adj_matrix[j][k] = adj_matrix[j][i] + adj_matrix[i][k];
                    // change the distance to the shortest distance
                }
            }
        }
    }

    int best_meetup_city = 0; // solution initialized to 0
    int temp_distance = INT_MAX; // temporary distance set to infinity

    // loop iterating through all cities
    for (int i = 0; i < n; i++) {
        if (i != p && i != q) { // cannot be either your or your friend's city
            int temp = adj_matrix[p][i]+adj_matrix[q][i];
            if (temp < temp_distance) { // shortest distance for both
                temp_distance = temp;
                best_meetup_city = i; // sets best meetup city to index
            }
        }
    }
    return best_meetup_city;
}

// free the dynamically allocated memory
void freeMemory(int n, int **&adj_matrix) {
    for (int i = 0; i < n; i++) {
        delete adj_matrix[i];
    }
    delete[] adj_matrix;
}
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    while (1) {
        std::cout << "Hello World!" << std::endl;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast  
            <std::chrono::seconds>(stop-start);
        std::cout << duration.count() << std::endl;
        if (duration.count() > 3) {
            exit(0);
        }
    }
}
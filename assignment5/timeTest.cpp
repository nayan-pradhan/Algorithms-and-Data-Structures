#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::this_thread::sleep_for (std::chrono::seconds(10));
    // auto start = std::chrono::high_resolution_clock::now();
    while (1) {
        std::cout << "Hello World!" << std::endl;
        // if (std::chrono::duration<int> a = chrono::system_clock::now() - start);
    }
}
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

void print(std::map<std::string, std::string> myMap) {
    std::map<std::string, std::string>::iterator itr;
    for (itr = myMap.begin(); itr!=myMap.end(); itr++) {
        std::cout << itr->first << " -> " << itr->second << std::endl;
    }
}

template <class T, class K>
bool practice(std::map<T, K> obj) {
    std::cout << "Welcome to my german quiz!" << std::endl;
    std::cout << "Write down the english translation for the words. Good luck!" << std::endl;
    std::cout << "Enter 'QUIT' to exit game" << std::endl;
    typename std::map<T,K>::iterator itr = obj.begin();
    K answer;
    while (1) {
        std::cout << itr -> first << " -> ";
        std::cin >> answer;
        if (answer == itr -> second) {
            itr++;
        }
        else if (answer == "QUIT") {
            std::cout << "Thank you for playing!" << std::endl;
            exit(-1);
        }
        else if (answer == "admin") {
            return true;
        }
        else {
            std::cout << "Try again!" << std::endl;
            continue;
        }
        if (itr == obj.end()) {
            std::cout << "Congradulations, you won!" << std::endl;
            return true;
        }
    }
}

int main() {
    std::map<std::string, std::string> Translator;
    Translator["Büro"] = "Office";
    Translator["Beruf"] = "Job";
    Translator["Praktikum"] = "Internship";
    Translator["Mitarbeiterinnen"] = "Co-workers";
    Translator["Chef"] = "Boss";
    //
    Translator.insert(std::pair<std::string, std::string>("Termin", "Meeting")); // learn this
    //
    Translator.insert(std::pair<std::string, std::string>("Pause", "Break"));
    Translator.insert(std::pair<std::string, std::string>("Arbeitet", "Work"));
    
    std::map<int, std::string> Numbers;
    Numbers = {{1, "Ein"}, {2, "Zwei"}, {3, "Drei"}, {4, "Vier"}, {5, "Fünf"},
        {6, "Sechs"}, {7, "Sieben"}, {8, "Acht"}, {9, "Neun"}, {10, "Zehn"}};
    
    std::cout << "Select which one you would want to practice:" << std::endl;
    std::cout << "1. Translator" << std::endl;
    std::cout << "2. Numbers" << std::endl;
    std::cout << "3. All" << std::endl;
    std::cout << "Enter 1, 2, or 3 -> ";
    int input;
    std::cin >> input;
    switch(input) {
        case 1:
            practice(Translator);
            break;
        case 2:
            practice(Numbers);
            break;
        default:
            practice(Translator);
            practice(Numbers);
    }
}
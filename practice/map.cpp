#include <iostream>
#include <map>

void print(std::map<std::string, std::string> myMap) {
    std::map<std::string, std::string>::iterator itr;
    for (itr = myMap.begin(); itr!=myMap.end(); itr++) {
        std::cout << itr->first << " -> " << itr->second << std::endl;
    }
}

bool practice(std::map<std::string, std::string> Translator) {
    std::cout << "Welcome to my german quiz!" << std::endl;
    std::cout << "Write down the english translation for the words. Good luck!" << std::endl;
    std::cout << "Enter 'QUIT' to exit game" << std::endl;
    std::map<std::string, std::string>::iterator itr = Translator.begin();
    std::string answer;
    while (1) {
        std::cout << itr -> first << " -> ";
        std::cin >> answer;
        if (answer == itr -> second) {
            itr++;
        }
        else if (answer == "QUIT") {
            std::cout << "Thank you for playing!" << std::endl;
            return false;
        }
        else {
            std::cout << "Try again!" << std::endl;
            continue;
        }
        if (itr == Translator.end()) {
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
    practice(Translator);
}
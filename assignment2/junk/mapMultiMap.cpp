#include <iostream>
#include <map>
using namespace std;

// int main() {
//     map <char, int> myMap;
//     for (char ch = 'a'; ch <= 'z'; ch++) {
//         myMap[ch] = (int) ch;
//     }
//     map <char, int>::iterator itr;
//     for (itr = myMap.begin(); itr != myMap.end(); itr++) {
//         cout << (*itr).first << " " << (*itr).second;
//         cout << endl;
//     }   
//     cout << myMap['k'];
//     return 0; 
// }

int main() {
    std::multimap<char, int> myMM;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        myMM[ch] = (int)ch;
    }
    multimap <char, int>::iterator itr;
    for (itr = myMM.begin(); itr != myMM.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }   
    myMM['k'] = 10000;
    cout << myMM['k'];
    return 0; 
}
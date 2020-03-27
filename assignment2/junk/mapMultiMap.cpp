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
    multimap <char, int> mymultimap;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        mymultimap[ch] = (int) ch;
    }
    multimap <char, int>::iterator itr;
    for (itr = mymultimap.begin(); itr != mymultimap.end(); itr++) {
        cout << (*itr).first << " " << (*itr).second;
        cout << endl;
    }   
    multimap['k'] = 10000;
    cout << mymultimap['k'];
    return 0; 
}
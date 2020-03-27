#include <iostream>
#include <deque>
#include <list>
#include <forward_list>
#include <vector>

using namespace std;

bool isEven (const int& val) {
    return (val%2) == 0;
}

int main () {
    cout << "\n";
    //vector
    cout << "VECTOR:" << endl;
    vector<int>vec1;
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(7);
    vec1.push_back(2);
    for (int i : vec1) {
        cout << i << " ";
    }
    cout << "\n";
    vec1.pop_back();
    for (int i : vec1) {
        cout << i << " ";
    }
    cout << "\n";
    cout << vec1[3];
    cout << "\n";

    //deque
    cout << "DEQUE:" << endl;
    deque<char> deq1 = {'a', 'b', 'c'};
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";
    deq1.push_back('d');
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";
    deq1.push_front('z');
    deq1.push_front('x');
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";
    deq1.pop_back();
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";
    deq1.pop_front();
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";

    cout << deq1.size() << endl;
    cout << deq1[2] << endl; 
    cout << "\n";

    deque<char>::iterator it = deq1.begin();
    it += 3;
    deq1.insert(it, 't');
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";

    deq1.erase(deq1.begin(), deq1.begin()+2);
    for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";

    deq1.clear();
        for (char ch : deq1) {
        cout << ch << " ";
    }
    cout << "\n";
}
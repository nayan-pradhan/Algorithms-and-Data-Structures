/* 
    CH-231-A
    10.1b cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

#include <iostream>

class Node {
    public:
        int key;
        int value;
        Node(int key, int value);
};

Node::Node(int key, int value) {
    this -> key = key;
    this -> value = value;
}

class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public: 
        HashTable(int maxSize = 25); // parametric constructor w/ def size
        ~HashTable(); // destructor
        int hashCode(int key); // hash function to generate hash COde
        void insertNode(int key, int value); // insert nito hash table
        int get(int key); // takes key, returns value
        bool isEmpty(); //checks to see if hash table is empty 
        //setters and getters
        void setMaxSize(int newSize) 
            {maxSize = newSize;}
        int getMaxSize() 
            {return maxSize;}
        void setCurrentSize(int newCurrSize) 
            {currentSize = newCurrSize;}
        int getCurrentSize() 
            {return currentSize;}
};

// parametric constructor
HashTable::HashTable(int maxSize) {
    this -> maxSize = maxSize;
    currentSize = 0;
    arr = new Node*[maxSize];
    for (int i = 0; i < maxSize; i++) {
        arr[i] = nullptr;
    }
}

// destructor
HashTable::~HashTable() {
    for (int i = 0; i < maxSize; i++) {
        delete arr[i];
    }
    delete[] arr;
    std::cout << "Destructor called!" << std::endl;
}

// isEmpty bool function
bool HashTable::isEmpty() {
    if (currentSize == 0) {
        std::cout << "Hash Table is Empty!" << std::endl;
        return true;
    }
    else {
        std::cout << "Hash Table is Not Empty!" << std::endl;
        return false;
    }
}

// generate hashCode
int HashTable::hashCode(int key) {
    return (key % maxSize); 
}

// insert node into Hash Table
void HashTable::insertNode(int key, int value) {
    int i = 0;
    while (i != maxSize) {
        int j = (hashCode(key)+i) % maxSize;
        if (arr[j] == nullptr) {
            std::cout << "Inserting " << value << " in hash table." 
                << std::endl;
            arr[j] = new Node(key, value);
            currentSize++;
            return;
        }
        else {
            i++;
        }
    }
    if (i == maxSize) {
        throw std::logic_error("Hash Table Full");
    }
}

// input key and get value
int HashTable::get(int key) {
    int i = 0;
    while (i != maxSize) {
        int j = (hashCode(key)+i) % maxSize;
        if (arr[j] == nullptr) {
            throw std::logic_error ("Not found");
        }
        else if (key == (arr[j] -> key)) {
            std::cout << arr[j] -> key << " -> ";
            return (arr[j] -> value);
        }
        else {
            i++;
        }
    }
    throw std::logic_error ("Not found");
}

// main
int main() {
    HashTable myHashTable(5); // creating hashTable
    myHashTable.isEmpty(); // checking if empty or not
    // inserting key and value
    try {
        myHashTable.insertNode(1212, 3);
        myHashTable.insertNode(2323, 89);
        myHashTable.insertNode(3434, 234);
        myHashTable.insertNode(4545, 4321);
        myHashTable.insertNode(5656, 34);
        myHashTable.insertNode(67, 421); // overflow case
    } catch (std::logic_error) {
        std::cout << "Hash Table is Full!" << std::endl;
    }
    // get value from key
    try {
        std::cout << "Key  -> Value" << std::endl;
        std::cout << myHashTable.get(2323) << std::endl;
        std::cout << myHashTable.get(1212) << std::endl;
        std::cout << myHashTable.get(3434) << std::endl;
        std::cout << myHashTable.get(5656) << std::endl;
        std::cout << myHashTable.get(67) << std::endl; //key doesnt exist
    } catch (std::logic_error) {
        std::cout << "Key does not exist in Hash Table!" << std::endl;
    }
    myHashTable.isEmpty(); // checking if empty or not
}
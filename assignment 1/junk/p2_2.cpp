#include <iostream>

template <class T>
class Stack {
    private:
        int size;
        T *arr;
    public:     
        Stack();
        Stack(const Stack&);
        Stack(int size);
        bool isFull(const Stack&); //isFull?
        bool push (T element);
        bool pop (T& out);
        T back (void);
        int getNumEntries();
};

//function that checks whether stack is full or not
template <class T>
bool Stack<T>::isFull(const Stack& st) {
    if (st.size == size) {
        return 1;
    }
    else {
        return -1;
    }
}

//default constructor
template <class T>
Stack<T>::Stack() {
    size = 10;
}

//copy constructor
template <class T>
Stack<T>::Stack(const Stack& obj) {
    this -> size = obj.size;
    for (int i = 0; i < sizeof(arr); i++) {
        this -> arr[i] = obj.arr[i];
    }
}

//parametric constructors
template <class T>
Stack<T>::Stack(int size) {
    this -> size = size;
}

template <class T>
bool push (T element) {
    if (isFull(Stack) == 1) {
        return false;
    }
    else {
        
    }
}

int main() {

    return 0;
}
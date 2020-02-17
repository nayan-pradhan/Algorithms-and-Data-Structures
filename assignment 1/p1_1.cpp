/* 
    CH-231-A
    a1 p1 cpp 
    Nayan Man Singh Pradhan 
    n.pradhan@jacobs-university.de
*/

/* 
    arr -> array
    num -> number of elements in array
    e -> int element that is searched
    f -> char element that is searched
*/

#include <iostream>

using namespace std;

template <class T> //template
int array_search(T arr[], int num, T e);
//complex class
class Complex {
    private:
        double real;
        double imag;
    public:
        //parametric constructor
        Complex (double real, double imag) {
            this -> real = real;
            this -> imag = imag;
        }
        //operator overloading for =
        Complex &operator = (const Complex obj) {
            this -> real = obj.real;
            this -> imag = obj.imag;
            return *this;
        }
        //operator overloading for +
        Complex operator+(const Complex obj) {
            return Complex(this -> real + obj.real, this -> imag + obj.imag);
        }

        //declarationf for operation overloading for << (overloaded later)
        friend ostream& operator <<(ostream &output, const Complex &c);

        //operator overloading for ==
        bool operator==(const Complex obj) {
            if ( (this->real == obj.real) && (this->imag == obj.imag) ) {
                return true;
            }
            else {
                return false;
            } 
        }
};
//operation overloading for <<
ostream& operator <<(ostream &output, const Complex &c) {
    if (c.imag) {
        output << noshowpos << c.real << showpos << c.imag << "i" << endl;
    }
    else {
        output << noshowpos << c.real << showpos << endl;
    }
    return output;
}     

//main function
int main() {

    //integers
    int intArr[5] = {1, 2, 3, 4, 5};
    int e = 3;
    cout << array_search(intArr, 5, e) << endl;

    //characters
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};
    char f = 'd';
    cout << array_search(charArr, 5, f) << endl;

    //complex class
    Complex compArr[5] = {Complex(1,2), Complex(3,4), Complex(5,6), Complex(8,9),
        Complex(5,8)};
    Complex g = Complex(5, 6);
    cout << array_search(compArr, 5, g) << endl;
    
    return 0;
}

//array search function using template class
template <class T>
int array_search(T arr[], int num, T e) {
    for (int i = 0; i < num; i++) {
        if (arr[i] == e) {
            return i+1;
        }
    }
    return -1;
}


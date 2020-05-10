#include <iostream>
#include <vector>
using namespace std;

class Complex {
    private:
        int real;
        int imag;
    public:
        void setReal(int real) {this->real = real;}
        void setImag(int imag) {this->imag = imag;}
        int getReal() {return real;}
        int getImag() {return imag;}
        Complex() {
            real = imag = 0;
        }
        Complex (int real, int imag) {
            setReal(real);
            setImag(imag);
        }
        Complex operator+ (const Complex obj) {
            return Complex(this->real+obj.real, this->imag+obj.imag);
        }
        void operator= (const Complex obj) {
            this -> real = obj.real;
            this -> imag = obj.imag;
        }
        bool operator== (const Complex obj) {
            if (this->real == obj.real && this->imag == obj.imag) {
                return true;
            }
            else {
                return false;
            }
        }
        friend ostream& operator<< (ostream& output, const Complex obj) {
            if (obj.imag) {
                std::cout << obj.real << showpos << obj.imag << "i" << std::endl;
            }
            else {
                std::cout << obj.real << std::endl;
            }
            return output;
        }
};

template <class T>
bool arraySearch(vector<T> list, T lookFor) {
    typename vector<T>::iterator itr;
    for (itr = list.begin(); itr != list.end(); itr++) {
        if (*itr == lookFor) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> intVec = {1,2,3,4,5,6,7,8,9};
    int lookForInt = 3;
    std::cout << arraySearch(intVec, lookForInt) << std::endl;

    vector<string> strVec = {"hello", "world", "this", "is", "nayan"};
    string lookForString = "asdf";
    std::cout << arraySearch(strVec, lookForString) << std::endl;

    vector<Complex> complexVector = {Complex(1,2), Complex(2,3), Complex(3,4)};
    Complex lookForComplex = Complex(1,2);
    std::cout << arraySearch(complexVector, lookForComplex) << std::endl;
}
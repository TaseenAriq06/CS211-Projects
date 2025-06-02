#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag; // real: real number; imag: imaginary unit
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i;}

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const& object) {
        Complex result;
        result.real = real + object.real;
        result.imag = imag + object.imag;
        return result;
    };

    // This is automatically called when '-' is used with
    // between two Complex objects
    Complex operator - (Complex const& object) {
        Complex result;
        result.real = real - object.real;
        result.imag = imag - object.imag;
        return result;
    }
    // This is automatically called when '*' is used with
    // between two Complex objects
    Complex operator * (Complex const& object) {
        Complex result;
        result.real = real * object.real - imag * object.imag;
        result.imag = object.real * imag + real * object.imag;
        return result;
    }

void print() { cout << real << " + " << imag << "i" << endl; }

};

int main(){
    Complex c1(6, 3), c2(7, -1);
    c1.print();
    c2.print();

    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    Complex c4 = c1 - c2; // An example call to "operator-"
    c4.print();
    Complex c5 = c1 * c2; // An example call to "operator*"
    c5.print();
    
    return 0;
}

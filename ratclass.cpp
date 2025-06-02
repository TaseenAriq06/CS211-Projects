// Taseen Ariq
// Rat Class
#include <iostream>
#include <cstdlib> 
using namespace std;

class Rat { // Class to represent rational numbers (fractions)
private:
    int n; // numerator
    int d; // denominator

    int gcd(int x, int y){
        x = abs(x); // Make 'a' positive
        y = abs(y); // Make 'b' positive 
        while (y != 0){
            int temp = y;
            y = x % y; // Uses Euclidean Algorithm - mods a and b until remainder = 0, uses remainder before 0 as 'a'.
            x = temp;
        }
        return x;
    }

    void reduce(){  // Reduces the fraction to its simplest form
        int g = gcd(n, d);
        n /= g; // Divide numerator by GCD
        d /= g; // Divide denominator by GCD
        if (d < 0){ // Keep denominator positive 
            n = -n;
            d = -d;
        }
    }

public:
    // Default constructor: sets fraction to 0/1
    Rat(){ 
        n = 0;
        d = 1;
    }
    
    // Constructor with numerator and denominator
    Rat(int i, int j){
        n = i;
        d = j;
        reduce();
    }
    
    // Constructor with whole number, and makes denominator 1
    Rat(int i){
        n = i;
        d = 1;
    }

    // Overload - operator to subtract two fractions
    Rat operator - (Rat const& t){
        return Rat(n * t.d - t.n * d, d * t.d); // Formula: (a/b - c/d) = (ad - bc) / bd
    }

    // Overload * operator to multiply two fractions
    Rat operator * (Rat const& t){
        return Rat(n * t.n, d * t.d);           // Formula: (a/b * c/d) = (a * c) / (b * d)
    }

    // Overload / operator to divide two fractions
    Rat operator / (Rat const& t){
        return Rat(n * t.d, d * t.n);           // Formula: (a/b / c/d) = (a * d) / (b * c)
    }

    // Overload + operator to add two fractions
    Rat operator + (Rat const& t){
        return Rat(n * t.d + d * t.n, d * t.d); // Formula: (a/b + c/d) = (a * d + b * c / b * d)
    }

    Rat operator == (Rat const&t){
        return Rat(n * t.d == d * t.n);         // Formula: (a/b == c/d) = (a*d == b*c)
    }

    // friend ostream & operator << (ostream& os, Rat r);
    // friend istream & operator >> (istream& is, Rat& r);

    // ostream& operator<<(ostream& os, Rat r){
    //    os << t.n << "/" << "t.d" << endl;
    // }

    // istream& opeartor>>(istream& os, Rat r){
    //    char slash;
    //    is >> t.n >> slash >> t.d;
    // }

    

    // Print the fraction in simplified or mixed form
    void print(){
        reduce();
        if (abs(n) < d){                   // If (positive) numerator is smaller than denominator
            cout << n << "/" << d << endl; // print as regular fraction
        } else if (n % d == 0){            // whole number integer when divided has a remainder of 0
            cout << n / d << endl;
        } else {                           // mixed number
            int whole = n / d;
            int remainder = abs(n % d);
            cout << whole << " " << remainder << "/" << d << endl;
        }
    }
};

int main() {
    int a, b, x, y;
    cout << "Enter numerator and denominator for the first fraction (with space): ";
    cin >> x >> y;
    while(y == 0){
        cout << "Denominator cannot be 0, try again: ";
        cin >> x >> y;
    }
    cout << endl;

    cout << "Enter numerator and denominator for the second fraction (with space): ";
    cin >> a >> b;
    while (b == 0){
        cout << "Denominator cannot be 0, try again: ";
        cin >> a >> b;
    }
    cout << endl;

    Rat f1(x, y);   // prints x/y
    Rat f2(a, b);   // prints a/b 

    cout << "f1 = "; f1.print();
    cout << "f2 = "; f2.print();

    cout << "_______________________" << endl;

    Rat f6 = f1 + f2;
    cout << "f1 + f2 = "; f6.print(); 

    Rat f3 = f1 - f2;
    cout << "f1 - f2 = "; f3.print();

    Rat f4 = f1 * f2;
    cout << "f1 * f2 = "; f4.print();

    Rat f5 = f1 / f2;
    cout << "f1 / f2 = "; f5.print();

    Rat f7 = f1 == f2;
    cout << "f1 == f2 = "; f7.print(); 

    return 0;
}

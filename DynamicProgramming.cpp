#include <iostream>
using namespace std;

int fibonacci(int n) {
    static int memo[100] = {0}; // initialized to 0s

    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int factorial (int n){ // factorial of a number
    static int memo[100] = {0};

    if(n <= 1) return 1;
    if(memo[n] != 0) return memo[n];

    return memo[n] = n * factorial(n-1);
}

int natural (int n){ // add natural numbers 
    static int memo[100] = {0};

    if(n <= 1) return 1;
    if(memo[n] != 0) return memo[n];

    return memo[n] = n + natural(n-1);
}

int main() {
    int a, b, c;
    cout << "Enter a: ";
    cin >> a;
    
    cout << "Enter b: ";
    cin >> b;
    
    cout << "Enter c: ";
    cin >> c;
    
    cout << endl; 
    
    for(int i = 0; i < a; i++){
        cout << "fibonacci(" << i << ") = " << fibonacci(i) << endl;
    }
    cout << endl;

    cout << "factorial(" << b << "): " << factorial(b) << endl;
    cout << "natural(" << c << "): " << natural(c) << endl;
    return 0;
} 

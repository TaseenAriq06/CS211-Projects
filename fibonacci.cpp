#include <iostream>
using namespace std;

int fib(int n) {
    static int memo[100] = {0}; // initialized to 0s

    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];

    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int fact (int n){
    static int memo[100] = {0};

    if(n <= 1) return 1;
    if(memo[n] != 0) return memo[n];

    return memo[n] = n * fact(n-1);
}

int nat (int n){
    static int memo[100] = {0};

    if(n <= 1) return 1;
    if(memo[n] != 0) return memo[n];

    return memo[n] = n + nat(n-1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;
    
    for(int i = 0; i < n; i++){
        cout << "fib(" << i << ") = " << fib(i) << endl;
    }

    cout << fact(10) << endl;
    cout << nat(10) << endl;
    return 0;
} 

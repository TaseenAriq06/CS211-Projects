#include <iostream>
using namespace std;

bool ok(int q[], int c) { 
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) return false; // Check for same row or diagonal conflict
    }
    return true;
}

int nqueens(int n) {
    int solutions = 0;
    int *q = new int[n]; // array to hold queen positions (index = column, value = row)
    int c = 0; 
    q[0] = 0;

    while (c >= 0) {
        c++;
        if (c == n) { // if all queens placed (found solution)
            solutions++;
            c--; 
        } else {
            q[c] = -1; // start this column with row -1 (will increment next)
        }

        while (c >= 0) {
            q[c]++;
            if (q[c] == n) { // if past last row, backtrack
                c--; 
            } else if (ok(q, c)) { // if placement is safe, go to next column
                break; 
            }
        }
    }
    
    delete[] q; // delete the memory allocated for the array 
    return solutions; // return total solutions found
}

int main() {
   int n;

   cout << "Enter n amount of queens: ";
   cin >> n;
   cout << endl;
   
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
   

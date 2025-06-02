#include <iostream>
using namespace std;

bool ok(int q[], int c) { // position #'s in the cross format & -1 is to signify no more adjacent numbers
    static int a[8][5] = { 
        {-1},           
        {0, -1},          // 1 is adjacent to 0                           0 1 
        {0, -1},          // 2 is adjacent to 0                         2 3 4 5
        {0, 1, 2, -1},    // 3 is adjacent to 0, 1, 2                     6 7
        {0, 1, 3, -1},    // 4 is adjacent to 0, 1, 3
        {1, 4, -1},       // 5 is adjacent to 1, 4
        {2, 3, 4, 7, -1}, // 6 is adjacent to 2, 3, 4, 7
        {3, 4, 5, 6, -1}  // 7 is adjacent to 3, 4, 5, 6
    };

    // Test all numbers are different in cross array
    for (int i = 0; i < c; i++) {
        if (q[c] == q[i]) return false;
    }
    
    // Test adjacent numbers are not consecutive
    int i = 0;
    while (a[c][i] != -1) {
        if (abs(q[c] - q[a[c][i]]) == 1) return false;
        i++;
    }
    return true;
}

void print(int q[]) { // print the cross platform + every possible solution
    static int sol = 1;
    cout << "Solution #" << sol++ << ":" << endl;
    cout << "  " << q[0] << " " << q[1] << endl; // prints first 2 positions
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl; // prints 4 positions
    cout << "  " << q[6] << " " << q[7] << endl << endl; // prints last 2 positions
}

int main() {
    int q[8] = {0}, c = 0; // q stores numbers, c is the index
    while (c >= 0) {
        q[c]++; // Try next number

        if (q[c] > 8) { // If number goes over 8, backtrack
            q[c] = 0;
            c--;
        } 
        
        else if (ok(q, c)) { // If valid placement, move to next position
            if (c == 7) { // If all numbers placed, print solution
                print(q);
                c--;
            } else {
                c++;
            }
        }
    }
    
    return 0;
}

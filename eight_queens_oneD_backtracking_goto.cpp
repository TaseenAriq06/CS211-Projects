// Taseen Ariq
// 8 Queens 1D->2D Array with Backtracking & GOTO
#include <iostream>
using namespace std;

int main() {
    int q[8] = {0}, c = 0; // initialize 1D array and every number signifies the row # out of 8 columns
    int solutioncount = 1;

nc: // new column
    c++;
    if (c == 8) goto print;
    q[c] = -1;

nr: // new row
    q[c]++;
    if (q[c] == 8) goto backtrack;
    
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) goto nr; // test for row or up & down diagonal conflicts
    }
    goto nc;

backtrack:
    c--;
    if (c == -1) return 0; // backtrack column and try next row
    goto nr;

print:
    cout << "Solution " << solutioncount++ << ":" << endl;
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            if(i == q[j]) cout << "1 "; // print the 1 in the row # for each column in a 2d array format
            else cout << "0 ";
            
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
    
    return 0;
}

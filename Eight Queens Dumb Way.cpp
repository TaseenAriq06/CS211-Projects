#include <iostream>
using namespace std;

bool ok(int q[], int c) { // function to see if it is ok to place a queen 
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) return false; // test to see if there are queens in the row or diagonal
    }
    return true;
}

void print(int q[], int &solutioncount) { // function to print the board of solutions
    cout << "Solution " << solutioncount++ << ":" << endl;
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (r == q[c]) cout << "1 "; // prints 1 for a queen placed and 0 is empty spots
            else cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int q[8] = {}, solutioncount = 1; // initialize the board and solutions

    for (int c0 = 0; c0 < 8; c0++) { // loop through first column for a row placement 
        q[0] = c0;
        for (int c1 = 0; c1 < 8; c1++) { // loop through second column
            q[1] = c1;  // place the queen
            if (!ok(q, 1)) continue; // skip if not a valid position
            for (int c2 = 0; c2 < 8; c2++) { // loop through third column
                q[2] = c2; // place the queen
                if (!ok(q, 2)) continue; // skip if not a valid position
                for (int c3 = 0; c3 < 8; c3++) { // loop through fourth column
                    q[3] = c3; // place the queen
                    if (!ok(q, 3)) continue; // skip if not a valid position
                    for (int c4 = 0; c4 < 8; c4++) { // loop through fifth column
                        q[4] = c4; // place the queen
                        if (!ok(q, 4)) continue; // skip if not a valid position
                        for (int c5 = 0; c5 < 8; c5++) { // loop through sixth column
                            q[5] = c5; // place the queen
                            if (!ok(q, 5)) continue; // skip if not a valid position
                            for (int c6 = 0; c6 < 8; c6++) { // loop through seventh column
                                q[6] = c6; // place the queen
                                if (!ok(q, 6)) continue; // skip if not a valid position
                                for (int c7 = 0; c7 < 8; c7++) { // loop through eigth column
                                    q[7] = c7; // place the queen
                                    if (ok(q, 7)) { // checks if entire board is valid
                                        print(q, solutioncount); // prints the solution
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

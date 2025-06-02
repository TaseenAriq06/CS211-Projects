#include <iostream>
using namespace std;

int main() {
    int b[8][8] = {0}, r, c = 0; // initializing the 8 x 8 chess board
    b[0][0] = 1;
    int solutioncount = 1;

nc: // new column
    c++;
    if (c == 8) goto print;
    r = -1;

nr: // new row
    r++;
    if (r == 8) goto backtrack;

    for (int i = 0; i < c; i++) {
        if (b[r][i] == 1) goto nr; // if there is a spot for a queen place 1
    }
    
    for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
        if (b[r - i][c - i] == 1) goto nr; // up diagonal test
    }
    
    for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
        if (b[r + i][c - i] == 1) goto nr; // down diagonal test
    }

    b[r][c] = 1; // place the queen
    goto nc; // try to place another queen

backtrack:
    c--;
    if (c == -1) return 0;
    
    r = 0;
    while (b[r][c] != 1) {
        r++; // no valid position so backtrack and remove that queen
    }
    b[r][c] = 0;
    goto nr;

print:
    cout << "Solution " << solutioncount++ << ":" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(b[i][j] == 1)
                cout << "1 "; // if there is a Queen placed
            else cout << "0 "; // areas where there is no Queen placed
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
    
    return 0;
}

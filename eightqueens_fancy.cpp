// Taseen Ariq
// 8 Queens Fancy Print Chessboard
#include <iostream>
using namespace std;

// Checks if placing a queen at column c is safe (no row or diagonal conflict)
bool ok(int q[], int c){
    for(int i = 0; i < c; i++){
        if(q[c] == q[i] || abs(q[c] - q[i]) == c - i) return false;
    }
    return true;
}

// Moves back one column if queen placement invalid
void backtrack(int &c){
    c--;
}

int main(){
    int q[8] = {}, c = 0, count = 1;
    int i, j, k, l;
    q[0] = -1; // start off before row 0 so the loop puts the first queen in row 0

    // Define a 2D character array for each board square
    typedef char box[5][7];
    box bb, wb, wq, bq, *board[8][8]; // bb = black box, wb = white box

    // Fill black and white boxes
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }

    // Design for queen displayed on white square
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++)
            wq[i][j] = ' ';
    wq[1][1] = wq[2][1] = wq[3][1] = char(219);
    wq[3][2] = char(219);
    wq[1][3] = wq[2][3] = wq[3][3] = char(219);
    wq[3][4] = char(219);
    wq[1][5] = wq[2][5] = wq[3][5] = char(219);

    // Design for queen displayed on black square
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++)
            bq[i][j] = char(219);
    bq[1][1] = bq[2][1] = bq[3][1] = ' ';
    bq[3][2] = ' ';
    bq[1][3] = bq[2][3] = bq[3][3] = ' ';
    bq[3][4] = ' ';
    bq[1][5] = bq[2][5] = bq[3][5] = ' ';

    // Backtracking loop
    while (c >= 0) {
        q[c]++; // move to the next row in current column
        while (q[c] == 8) {
            q[c] = -1;
            backtrack(c);
            if (c < 0) return 0; // all possible column solutions done
            q[c]++;
        }
        if (ok(q, c)) { // If it's a valid spot, move to next column
            c++;
            if (c == 8) { // Solution found

                // Set up the board with default squares
                for(i = 0; i < 8; i++) {
                    for(j = 0; j < 8; j++) {
                        if ((i + j) % 2 == 0)
                            board[i][j] = &wb; // white square
                        else
                            board[i][j] = &bb; // black square
                    }
                }
                // Place queens on the board
                for(int col = 0; col < 8; col++) {
                    int row = q[col];
                    if ((row + col) % 2 == 0)
                        board[row][col] = &wq; // queen for white square
                    else
                        board[row][col] = &bq; // queen for black square
                }
                // Print fancy board and all solutions
                cout << "Solution # " << count++ << ":" << endl;
                cout << "  ";
                for(i = 0; i < 7 * 8; i++) // Top border
                    cout << "_";
                cout << endl;

                for(i = 0; i < 8; i++)
                    for(k = 0; k < 5; k++){ // Each box is 5 characters tall (so we draw it row by row)
                        cout << "  " << char(179); // Print left border of the board (char(179) = │ vertical bar)
                        for(j = 0; j < 8; j++)
                            for(l = 0; l < 7; l++)  // Each box is 7 characters wide
                                cout << (*board[i][j])[k][l]; // Print the k-th row of the box at [i][j]
                        cout << char(179) << endl;  // Print right border and move to the next line
                    }

                cout << "  ";
                for(i = 0; i < 7*8; i++) 
                    cout << char(196); // Bottom border
                cout << endl << endl;

                // Backtrack for next solution
                backtrack(c);
            }
        }
    }

    return 0;
}

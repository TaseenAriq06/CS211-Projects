#include <iostream>
using namespace std;

bool ok(int q[], int c){ // preference list for men and women (0 is the best, 2 is the worst rating)
    static int mp[3][3] = { {0, 2, 1},   // Man 0 prefers Woman 0 > Woman 2 > Woman 1
                            {0, 2, 1},   // Man 1 prefers Woman 0 > Woman 2 > Woman 1
                            {1, 2, 0} }; // Man 2 prefers Woman 2 > Woman 0 > Woman 2
                            
    static int wp[3][3] = { {2, 1, 0},   // Woman 0 prefers Man 2 > Man 1 > Man 0
                            {0, 1, 2},   // Woman 1 prefers Man 0 > Man 1 > Man 2
                            {2, 0, 1} }; // Woman 2 prefers Man 1 > Man 2 > Man 0
                            
    for(int i = 0; i < c; i++){
        if (q[i] == q[c]) return false; // if two men are married to the same women return false
        if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false; // if man i and woman q[c] prefer each other over their current partners
        if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false; // if man c and woman q[i] prefer each other over their current partners
    }
    return true;
}

void print(int q[]){ // Prints the current solution with the man-to-woman pairing
    static int sol = 1;
    cout << "Solution #" << sol++ << ":\nMan\tWoman\n"; 
    for(int i = 0; i < 3; i++){
        cout << i << "\t" << q[i] << endl;
    }
    cout << endl;
}

int main(){
    int q[3] = {};              // initialize the array q to store the pairings (man to woman)
    int c = 0;                  // start with the first man at index 0
    
    while(c >= 0){ 
        if(c == 2){             // if a woman has been assigned to all 3 men
            print(q);
            --c;                // backtrack to find other solutions
        }
        else 
            q[++c] = -1;        // reset index to -1 for the next man to be assigned to a woman
        while(c >= 0){ 
            ++q[c];             // try the next woman
            if(q[c] == 3) --c;  // if the current man tried all 3 women backtrack to the previous man
            else if (ok(q,c))   // checks if pairing is valid
            break;              // go to the next man
        }
    }
    return 0;
}
    

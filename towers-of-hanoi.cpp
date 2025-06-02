// Taseen Ariq
// Towers of Hanoi
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; // Three towers represented as stacks
    int n, from = 0, candidate = 1, move = 0;

    cout << "Please enter the number of rings: ";
    cin >> n;
    cout << endl;

    int to;
    if (n % 2 == 0) to = 2; // Set the initial "to" tower based on whether n is even or odd
    else to = 1;

    for (int i = n + 1; i >= 1; --i) // Fill Tower A with all rings plus a n+1 starter ring
        t[0].push_back(i);  // Add a initial ring to Tower A
    t[1].push_back(n + 1); // Add a initial ring to Tower B
    t[2].push_back(n + 1); // Add a initial ring to Tower C

    while (t[1].size() < n + 1) { // Keep looping until tower B is full with all the rings the user entered
        cout << "Move #" << ++move << ": Transfer ring " 
        << candidate << " from tower " << char(from + 'A') 
        << " to tower " << char(to + 'A') << endl;

        t[to].push_back(candidate); // Move the candidate ring from the 'from' tower to the 'to' tower
        t[from].pop_back();

        if (t[(to + 1) % 3].back() > t[(to + 2) % 3].back()) // Choose the next 'from' tower, pick the tower with the smaller top ring
            from = (to + 2) % 3;
        else
            from = (to + 1) % 3;
        candidate = t[from].back(); // Update the candidate to the ring on top of the new from tower

        if (n % 2 == 0) { 
            if (candidate > t[(from + 2) % 3].back()) // For even n, move candidate counter-clockwise. For odd n, move clockwise.
                to = (from + 1) % 3;
            else
                to = (from + 2) % 3;
        } else {
            if (candidate > t[(from + 1) % 3].back()) // Compare the candidate with the ring on the closer tower
                to = (from + 2) % 3;
            else
                to = (from + 1) % 3;
        }
    }

    return 0;
}

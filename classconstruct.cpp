#include <iostream>
using namespace std;

class Test{
public: 
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }

    Test& operator = (const Test& t)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }
};

int main(){
    Test t1, t2;
    t2 = t1; // Assignment operator called
    Test t3 = t1; // Copy constructor called
    getchar();
    return 0;
}


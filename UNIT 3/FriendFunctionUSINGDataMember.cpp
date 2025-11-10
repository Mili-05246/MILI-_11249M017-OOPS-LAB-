
#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
private:
    int numA;

public:
    void setData(int a) {
        numA = a;
    }

    // Friend function declaration
    friend void add(A, B);
};

class B {
private:
    int numB;

public:
    void setData(int b) {
        numB = b;
    }

    // Friend function declaration
    friend void add(A, B);
};

// Friend function definition — can access private data of both classes
void add(A objA, B objB) {
    cout << "Sum of private data members = " << objA.numA + objB.numB << endl;
}

int main() {
    A objA;
    B objB;

    objA.setData(10);
    objB.setData(20);

    add(objA, objB);  // Friend function accessing private members

    return 0;
}


#include <iostream>
using namespace std;

// Forward declaration
class B;

class A {
    int numA;
public:
    A() {
        numA = 10;
    }

    // Declare friend function
    friend void showValues(A, B);

    // Declare friend class
    friend class B;
};

class B {
    int numB;
public:
    B() {
        numB = 20;
    }

    // Function of friend class accessing private data of A
    void displayA(A objA) {
        cout << "Accessing private member of A from class B: numA = " << objA.numA << endl;
    }

    // Declare friend function as friend of this class too
    friend void showValues(A, B);
};

// Friend function definition
void showValues(A objA, B objB) {
    cout << "Friend Function Access:" << endl;
    cout << "numA = " << objA.numA << endl;
    cout << "numB = " << objB.numB << endl;
}

int main() {
    cout << "--- Demonstrating Friend Class and Friend Function ---" << endl;

    A objA;
    B objB;

    // Friend function accessing private data of both classes
    showValues(objA, objB);

    // Friend class accessing private member of another class
    objB.displayA(objA);

    return 0;
}

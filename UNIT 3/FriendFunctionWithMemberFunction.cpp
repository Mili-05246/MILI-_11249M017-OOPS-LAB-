
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

    // Member function that calls a friend function
    void showSum(B objB);

    // Friend function declaration
    friend int add(A, B);
};

class B {
private:
    int numB;

public:
    void setData(int b) {
        numB = b;
    }

    // Friend function declaration
    friend int add(A, B);
};

// Friend function definition
int add(A objA, B objB) {
    return objA.numA + objB.numB;
}

// Member function of class A that uses the friend function
void A::showSum(B objB) {
    cout << "Sum using friend function: " << add(*this, objB) << endl;
}

int main() {
    A objA;
    B objB;

    objA.setData(15);
    objB.setData(25);

    objA.showSum(objB);  // Calls member function that uses friend function

    return 0;
}

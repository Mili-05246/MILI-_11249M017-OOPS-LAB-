
#include <iostream>
using namespace std;

class MathOperations {
public:
    // Function with one parameter
    int add(int a) {
        return a + 10;
    }

    // Function with two parameters
    int add(int a, int b) {
        return a + b;
    }

    // Function with three parameters
    float add(float a, float b, float c) {
        return a + b + c;
    }
};

int main() {
    cout << "--- Demonstrating Function Overloading (Member Functions) ---" << endl;

    MathOperations m;

    cout << "add(5) = " << m.add(5) << endl;
    cout << "add(4, 6) = " << m.add(4, 6) << endl;
    cout << "add(1.2, 3.4, 5.6) = " << m.add(1.2f, 3.4f, 5.6f) << endl;

    return 0;
}

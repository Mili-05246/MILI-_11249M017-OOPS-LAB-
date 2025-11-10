#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n--- Arithmetic Operations ---\n";
    cout << "Addition (+): " << a + b << endl;
    cout << "Subtraction (-): " << a - b << endl;
    cout << "Multiplication (*): " << a * b << endl;
    if (b != 0) {
        cout << "Division (/): " << (float)a / b << endl;
        cout << "Modulus (%): " << a % b << endl;
    } else {
        cout << "Division and Modulus not possible (b = 0)" << endl;
    }

    cout << "\n--- Increment and Decrement Operations ---\n";
    cout << "Pre-increment (++a): " << ++a << endl;
    cout << "Post-increment (a++): " << a++ << endl;
    cout << "After post-increment, a = " << a << endl;
    cout << "Pre-decrement (--a): " << --a << endl;
    cout << "Post-decrement (a--): " << a-- << endl;
    cout << "After post-decrement, a = " << a << endl;

    return 0;
}


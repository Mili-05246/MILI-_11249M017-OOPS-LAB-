
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n--- Assignment Operators ---\n";

    int c;

    c = a;
    cout << "Simple assignment (=): c = " << c << endl;

    c += b;
    cout << "Add and assign (+=): c = " << c << endl;

    c -= b;
    cout << "Subtract and assign (-=): c = " << c << endl;

    c *= b;
    cout << "Multiply and assign (*=): c = " << c << endl;

    if (b != 0) {
        c /= b;
        cout << "Divide and assign (/=): c = " << c << endl;

        c %= b;
        cout << "Modulus and assign (%=): c = " << c << endl;
    } else {
        cout << "Division and modulus assignment skipped (b = 0)" << endl;
    }

    cout << "Bitwise AND and assign (&=): " << (c &= a) << endl;
    cout << "Bitwise OR and assign (|=): " << (c |= a) << endl;
    cout << "Bitwise XOR and assign (^=): " << (c ^= a) << endl;
    cout << "Left shift and assign (<<=): " << (c <<= 1) << endl;
    cout << "Right shift and assign (>>=): " << (c >>= 1) << endl;

    return 0;
}

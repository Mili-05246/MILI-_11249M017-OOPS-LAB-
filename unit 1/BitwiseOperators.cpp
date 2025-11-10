
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n--- Bitwise Operators ---\n";
    cout << "Bitwise AND (&): " << (a & b) << endl;
    cout << "Bitwise OR (|): " << (a | b) << endl;
    cout << "Bitwise XOR (^): " << (a ^ b) << endl;
    cout << "Bitwise NOT (~a): " << (~a) << endl;
    cout << "Left Shift (a << 1): " << (a << 1) << endl;
    cout << "Right Shift (a >> 1): " << (a >> 1) << endl;

    return 0;
}

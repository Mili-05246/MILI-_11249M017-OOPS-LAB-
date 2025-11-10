
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n--- Relational Operators ---\n";
    cout << "Equal to (==): " << (a == b) << endl;
    cout << "Not equal to (!=): " << (a != b) << endl;
    cout << "Greater than (>): " << (a > b) << endl;
    cout << "Less than (<): " << (a < b) << endl;
    cout << "Greater than or equal to (>=): " << (a >= b) << endl;
    cout << "Less than or equal to (<=): " << (a <= b) << endl;

    return 0;
}

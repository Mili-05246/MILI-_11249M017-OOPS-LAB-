
#include <iostream>
using namespace std;

int main() {
    bool x, y;
    cout << "Enter two boolean values (0 or 1): ";
    cin >> x >> y;

    cout << "\n--- Logical Operators ---\n";
    cout << "Logical AND (x && y): " << (x && y) << endl;
    cout << "Logical OR (x || y): " << (x || y) << endl;
    cout << "Logical NOT (!x): " << (!x) << endl;

    return 0;
}

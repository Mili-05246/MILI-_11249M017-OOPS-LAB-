
#include <iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    void getData() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }

    // Overloading binary '+' operator
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c3;
    cout << "--- Binary Operator Overloading (Addition) ---" << endl;
    c1.getData();
    c2.getData();
    c3 = c1 + c2;  // Operator overloading in action
    cout << "Sum = ";
    c3.display();
    return 0;
}


#include <iostream>
using namespace std;

class Complex {
    float real;
    float imag;

public:
    // Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(float r, float i) {
        real = r;
        imag = i;
    }

    // Function to add two Complex numbers (object passed as argument)
    Complex add(Complex c2) {
        Complex temp;
        temp.real = real + c2.real;
        temp.imag = imag + c2.imag;
        return temp; // Returning object
    }

    // Function to display result
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    cout << "--- Passing Object as Argument and Returning Object ---" << endl;

    Complex c1(3.5, 2.5);
    Complex c2(1.2, 4.8);

    cout << "First Complex number: ";
    c1.display();

    cout << "Second Complex number: ";
    c2.display();

    Complex c3;            // Object to store result
    c3 = c1.add(c2);       // Passing object and returning object

    cout << "Result after addition: ";
    c3.display();

    return 0;
}

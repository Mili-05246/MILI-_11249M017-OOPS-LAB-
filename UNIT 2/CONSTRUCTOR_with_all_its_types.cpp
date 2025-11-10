
#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
    float marks;

public:
    // 1. Default Constructor
    Student() {
        roll = 0;
        name = "Unknown";
        marks = 0.0;
        cout << "Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    Student(int r, string n, float m) {
        roll = r;
        name = n;
        marks = m;
        cout << "Parameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor
    Student(const Student &s) {
        roll = s.roll;
        name = s.name;
        marks = s.marks;
        cout << "Copy Constructor Called" << endl;
    }

    // Function to display data
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    cout << "--- Demonstrating Constructors in C++ ---" << endl;

    
    Student s1;
    s1.display();

    // Parameterized constructor
    Student s2(101, "Rahul", 88.5);
    s2.display();

    // Copy constructor
    Student s3 = s2;
    s3.display();

    return 0;
}


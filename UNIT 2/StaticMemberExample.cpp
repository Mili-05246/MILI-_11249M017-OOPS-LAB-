
#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
    static int count; // Static data member

public:
    void getData() {
        cout << "Enter Roll and Name: ";
        cin >> roll >> name;
        count++; // Increment count whenever new student data is entered
    }

    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }

    static void showCount() { // Static member function
        cout << "Total number of students: " << count << endl;
    }
};

// Definition of static data member
int Student::count = 0;

int main() {
    cout << "--- Demonstrating Static Data Member and Static Member Function ---" << endl;

    Student s1, s2, s3;

    s1.getData();
    s2.getData();
    s3.getData();

    cout << "\n--- Student Details ---\n";
    s1.display();
    s2.display();
    s3.display();

    // Call static member function
    Student::showCount();

    return 0;
}

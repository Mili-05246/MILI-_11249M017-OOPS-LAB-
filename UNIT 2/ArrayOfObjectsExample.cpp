
#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;
    float marks;

public:
    void getData() {
        cout << "Enter Roll, Name, and Marks: ";
        cin >> roll >> name >> marks;
    }

    void display() {
        cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[n]; // Array of objects

    cout << "\n--- Enter Student Details ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        s[i].getData();
    }

    cout << "\n--- Displaying Student Details ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        s[i].display();
    }

    return 0;
}

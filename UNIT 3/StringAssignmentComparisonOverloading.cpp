
#include <iostream>
#include <string.h>
using namespace std;

class MyString {
    char str[100];

public:
    void getData() {
        cout << "Enter string: ";
        cin >> str;
    }

    void display() {
        cout << str;
    }

    // Overloading '=' operator for assignment
    void operator=(MyString &s) {
        strcpy(str, s.str);
    }

    // Overloading '==' operator for comparison
    bool operator==(MyString &s) {
        return strcmp(str, s.str) == 0;
    }
};

int main() {
    cout << "--- String Assignment and Comparison Using Operator Overloading ---" << endl;

    MyString s1, s2, s3;

    cout << "Enter first string:" << endl;
    s1.getData();

    cout << "Enter second string:" << endl;
    s2.getData();

    // Assignment
    s3 = s1;

    cout << "\nAfter assignment, s3 contains: ";
    s3.display();
    cout << endl;

    // Comparison
    if (s1 == s2)
        cout << "\nStrings are equal." << endl;
    else
        cout << "\nStrings are not equal." << endl;

    return 0;
}

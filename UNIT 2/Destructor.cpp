
#include <iostream>
using namespace std;

class Demo {
    int id;
public:
    // Constructor
    Demo(int i) {
        id = i;
        cout << "Constructor called for object " << id << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called for object " << id << endl;
    }

    void show() {
        cout << "Object ID: " << id << " is active." << endl;
    }
};

int main() {
    cout << "--- Demonstrating Constructor and Destructor ---" << endl;

    Demo d1(1); // Constructor called
    Demo d2(2); // Constructor called

    d1.show();
    d2.show();

    {
        cout << "\nCreating a block..." << endl;
        Demo d3(3); // Constructor called
        d3.show();
        cout << "Exiting block..." << endl;
    } // Destructor for d3 called here

    cout << "Back to main function." << endl;

    return 0;
}

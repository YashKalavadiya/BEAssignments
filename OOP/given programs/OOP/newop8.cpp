/ C++ program to call the overridden function
// from a member function of the derived class

#include <iostream>
using namespace std;

class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
   public:
    void print() {
        cout << "Derived Function" << endl;

        // call overridden function
        Base::print();  //calls the overridden function inside the Derived class.


    }
};

int main() {
    Derived derived1;
    derived1.print();
    return 0;
}
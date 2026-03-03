#include <iostream>
using namespace std;

// class - it is a blueprint of object.
//      it is a user-defined datatype.
// object - it is an instance of class.

// constructor - it is a function which has the same name as class.

// public - private - protected : access modifier
// rule enforce - developer
// polymorphism
// inheritance
// encapsulation
// abstraction

 class Student{
        public:
        int rollno;
        string name;
        int mobileno;
        char name[50];
        Student(int rollno){ // constructor // parameterized constructor // copy constructor
            cout << "constructor called" << endl;
            rollno = i;
        }
        ~Student(){
            cout << "destructor called" << endl;
        }
        
    };

int main(){
    int a;
    cout << "this is before initialization" << endl;
    Student s1(1); // initialization time
    cout << "this is after initialization" << endl;
    
}

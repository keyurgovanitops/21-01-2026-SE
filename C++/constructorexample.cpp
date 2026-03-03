#include <iostream>
using namespace std;


class A{
    public:
    A(){
        cout << "this is constuctor" << endl; // 4
    }
    ~A(){
        cout << "this is destructor" << endl; // 6
    }
};

void jatin(){
    
    cout << "this is before constructor" << endl; // 1
    cout << "this is after constructor" << endl; // 2
    cout << "just for fun" << endl; // 3
}

int main(){
    jatin();
    A a; // intialize 
    cout << "this is statement of main"; // 5
    return 0;
}
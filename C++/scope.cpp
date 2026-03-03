#include <iostream>
using namespace std;

int a = 5; // global scoped
void fn(){
    cout << a;
}

int main(){
    int a = 3; // local scoped
    {
        int b = 4; // block scoped
        cout << a;
    }
    // cout << b; // error: 'b' is out of scope here
    cout << a;

    return 0;
}


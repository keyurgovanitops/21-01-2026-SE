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

int main(){
    class Animal{
        public: 
        Animal(char arr[]){

        }
        int speakEnglish = 0;
        int canEat = 1;
        int canWalk = 1;
    };
    Animal cat("cat");
    
    
}
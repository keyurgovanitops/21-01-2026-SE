#include <iostream>
#include <cstring>
using namespace std;

// this - jyare hu class ni andar use karu tyare this no matlab class itself.

class Student{
    public: // memeber variable
    Student(int rollno, int id, const char name[], char Grade, const char address[])   
    {
        this->rollno = rollno;
        this->id = id;
        strcpy(this->name, name);
        this->Grade = Grade;
        strcpy(this->address, address);
    }
    int rollno;
    int id;
    char name[50];
    char Grade;
    char address[100];
    // member function
    void printTheStudent(){
        cout << "the student roll no : " << rollno << endl;
        cout << "the student id : " << id << endl;
        cout << "the student name : " << name << endl;
        cout << " the student grade : " << Grade << endl;
        cout << "address :"<< address << endl;
    }
};

int main(){
    char city[100] = ;
    Student Hetarth(1,756,"Hetarth", 'C', "mumbai");
    Hetarth.printTheStudent();

    char city2[100] = "Goa";

    Student avi(2, 654, "Avi", 'B', city2); 
    avi.printTheStudent();

    char city3[100] = "delhi";
    Student jatin(9, 9977, "Jatin", 'A', city3);
    jatin.printTheStudent();

    char city4[100] = "delhi";
    Student man(3, 100,"man", 'B', city4);
    man.printTheStudent();
    return 0;
}

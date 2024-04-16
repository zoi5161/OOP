#include "Student.h"

Student::Student(){
    this -> studentId = "";
    this -> grade = 0.0;
    this -> fullname = "";
}

Student::Student(string studentId, double grade, string fullname){
    this -> studentId = studentId;
    this -> grade = grade;
    this -> fullname = fullname;
}

Student::~Student(){}

void Student::setStudentId(string studentId){
    this -> studentId = studentId;
}

string Student::getStudentId(){
    return studentId;
}

void Student::setGrade(double grade){
    this -> grade = grade;
}

double Student::getGrade(){
    return grade;
}

void Student::setFullname(string fullname){
    this -> fullname = fullname;
}

string Student::getFullname(){
    return fullname;
}

void Student::Input(){
    string id, name;
    double score;

    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter Grade: ";
    cin >> score;

    cin.ignore();
    cout << "Enter Fullname: ";
    getline(cin, name);

    this -> studentId = id;
    this -> grade = score;
    this -> fullname = name;
}

void Student::Output(){
    cout << "Id: " << this -> studentId << endl;
    cout << "Grade: " << this -> grade << endl;
    cout << "Name: " << this -> fullname << endl << endl;
}
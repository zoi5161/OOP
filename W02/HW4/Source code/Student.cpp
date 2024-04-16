#include "Student.h"

Student::Student(){
    this -> studentId = nullptr;
    this -> gpa = 0.0;
    this -> fullname = nullptr;
    this -> address = nullptr;
}

Student::Student(const char *studentId, const double gpa, const char *fullname, const char *address){
    this -> studentId = new char[strlen(studentId) + 1];
    strcpy(this -> studentId, studentId);

    this -> fullname = new char[strlen(fullname) + 1];
    strcpy(this -> fullname, fullname);

    this -> address = new char[strlen(address) + 1];
    strcpy(this -> address, address);

    this -> gpa = gpa; 
}

Student::Student(const Student &other){
    this -> studentId = new char[strlen(other.studentId) + 1];
    strcpy(this -> studentId, other.studentId);

    this -> fullname = new char[strlen(other.fullname) + 1];
    strcpy(this -> fullname, other.fullname);

    this -> address = new char[strlen(other.address) + 1];
    strcpy(this -> address, other.address);

    this -> gpa = other.gpa;
}

Student::~Student(){
    delete []studentId;
    delete []fullname;
    delete []address;
    this -> studentId = nullptr;
    this -> gpa = 0.0;
    this -> fullname = nullptr;
    this -> address = nullptr;
}

istream &operator >>(istream &in, Student &p){
    char *id = new char[50];
    double gpa;
    char *name = new char[50];
    char *add = new char[100];

    cout << "Enter Student ID: ";
    in.getline(id, 50);


    cout << "Enter GPA: ";
    in >> gpa;

    in.ignore();
    cout << "Enter Full Name: ";
    in.getline(name, 50);

    cout << "Enter Address: ";
    in.getline(add, 100);

    p.studentId = new char[strlen(id) + 1];
    strcpy(p.studentId, id);

    p.fullname = new char[strlen(name) + 1];
    strcpy(p.fullname, name);

    p.address = new char[strlen(add) + 1];
    strcpy(p.address, add);

    p.gpa = gpa; 

    delete []id;
    delete []name;
    delete []add;

    return in;
}

ostream &operator << (ostream &out, const Student &p){
    out << "Student ID: " << p.studentId << endl;
    out << "GPA: " << fixed << setprecision(2) << p.gpa << endl;
    out << "Full Name: " << p.fullname << endl;
    out << "Address: " << p.address << endl;
    return out;
}
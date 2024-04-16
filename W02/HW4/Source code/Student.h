#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student{
    private:
        char *studentId;
        double gpa;
        char *fullname;
        char *address;
    public:
        Student();
        Student(const char *studentId, const double gpa, const char *fullname, const char *address);
        Student(const Student &other);
        ~Student();

        friend istream &operator >> (istream &in, Student &p);
        friend ostream &operator << (ostream &fout, const Student &p); 
};
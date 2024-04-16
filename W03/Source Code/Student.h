#pragma once 
#include <iostream>

using namespace std;

class Student
{
    private:
        string studentId;
        double grade;
        string fullname;
    public:
        Student();
        Student(string studentId, double grade, string fullname);
        ~Student();

        void setStudentId(string studentId);
        string getStudentId();

        void setGrade(double grade);
        double getGrade();

        void setFullname(string fullname);
        string getFullname();

        void Input();
        void Output();
};
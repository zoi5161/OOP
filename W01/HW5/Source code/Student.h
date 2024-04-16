#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Student{
private:
    double mathGrade;
    double englishGrade;
    double programmingGrade;

public:
    Student();
    void setGrades(double math, double english, double programming);
    double calculateAverageGrade();
    bool isExcellentStudent();
};

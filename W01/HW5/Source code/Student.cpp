#include "Student.h"

Student::Student(){
    mathGrade = 0.0;
    englishGrade = 0.0;
    programmingGrade = 0.0;
}

void Student::setGrades(double math, double english, double programming){
    mathGrade = math;
    englishGrade = english;
    programmingGrade = programming;
}

double Student::calculateAverageGrade(){
    return (mathGrade + englishGrade + programmingGrade) / 3.0;
}

bool Student::isExcellentStudent(){
    double averageGrade = calculateAverageGrade();
    return (averageGrade >= 8.0) && (mathGrade >= 6.5) && (englishGrade >= 6.5) && (programmingGrade >= 6.5);
}
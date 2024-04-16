#include "Student.cpp"

int main(){
    system("clear");
    double math, english, programming;
    Student student;

    cout << "Enter Math scores: ";
    cin >> math;

    cout << "Enter English score: ";
    cin >> english;

    cout << "Enter Programming score: ";
    cin >> programming;

    student.setGrades(math, english, programming);

    double averageGrade = student.calculateAverageGrade();

    cout << endl << "Average score: " << averageGrade << endl;

    if (student.isExcellentStudent())
        cout << "Comprehensively excellent student!" << endl;
    else
        cout << "Students do not meet the requirements for comprehensive excellence." << endl;

    return 0;
}

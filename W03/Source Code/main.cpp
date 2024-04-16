#include "Stack.h"
#include "Fraction.h"
#include "Student.h"
#include "Course.h"

int main(){
    system("clear");

    // Bài 1
    cout << "-------------------------" << endl;
    cout << "Homework 1:" << endl << endl;
    Stack<int> intStack(10);
    int tmpInt;
    intStack.push(3);
    intStack.push(2);
    intStack.push(1);

    cout << "After push 1, 2, 3" << endl;
    cout << "Stack <int>: [";
    while(!intStack.isEmpty()){
        tmpInt = intStack.getTop();
        intStack.pop();
        if(!intStack.isEmpty())
            cout << tmpInt << ',';
        else
            cout << tmpInt << ']' << endl << endl;
    }

    Stack<Fraction> fractionStack(5);
    Fraction tmpFrac;
    fractionStack.push(Fraction(3, 4));
    fractionStack.push(Fraction(1, 2));

    cout << "After push 1/2, 3/4" << endl;
    cout << "Stack <Fraction>: [";
    while(!fractionStack.isEmpty()){
        tmpFrac = fractionStack.getTop();
        fractionStack.pop();
        if(!fractionStack.isEmpty())
            cout << tmpFrac << ',';
        else
            cout << tmpFrac << ']' << endl << endl;
    }

    // Bài 2
    cout << "-------------------------" << endl;
    cout << "Homework 2:" << endl << endl; 

    Student X;

    X.Input();
    cout << endl << "Print student information" << endl;
    X.Output();


    // Bài 3
    cout << "-------------------------" << endl;
    cout << "Homework 3:" << endl << endl; 

    Course course("CSC10003_22CLC03", "Object-oriented programming method");

    Student student1("22127034", 9.0, "Gia Bảo");
    Student student2("22127327", 8.8, "Văn Tài");
    Student student3("22127339", 7.0, "Tô Thanh");

    course.enrollStudent(student1);
    course.enrollStudent(student2);
    course.enrollStudent(student3);

    course.saveToFile("course.txt");

    Course loadedCourse;
    loadedCourse.readFromFile("course.txt");
    loadedCourse.printStudents();
    return 0;
}

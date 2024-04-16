#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

class Course
{
private:
    string courseCode;
    string courseName;
    vector<Student> students;

public:
    Course(){
        courseCode = "";
        courseName = "";
    }

    Course(string courseCode, string courseName){
        this -> courseCode = courseCode;
        this -> courseName = courseName;
    }

    string getCourseCode(){
        return courseCode;
    }

    string getCourseName(){
        return courseName;
    }

    vector <Student> getList(){
        return students;
    }

    void enrollStudent(Student &student){
        students.push_back(student);
    }

    void enrollStudents(vector<Student> &studentList){
        students.insert(students.end(), studentList.begin(), studentList.end());
    }

    void unenrollStudent(string studentId){
        for(int i = 0; i < students.size(); i++)
            if(students[i].getStudentId() == studentId){
                students.erase(students.begin() + i);
                break;
            }
    }

    void unenrollStudents(vector<Student> &studentList){
        for(int i = 0; i < studentList.size(); i++){
            for(int j = 0; j < students.size(); j++){
                if(students[j].getStudentId() == studentList[i].getStudentId()){
                    students.erase(students.begin() + j);
                    break;
                }
            }
        }
    }

    vector<Student> getExcellentStudents(){
        vector<Student> excellentStudents;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() >= 9.5)
                excellentStudents.push_back(students[i]);
        return excellentStudents;
    }

    vector<Student> getPrettyGoodStudents(){
        vector<Student> prettyGoodStudents;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() >= 8.5 && students[i].getGrade() < 9.5)
                prettyGoodStudents.push_back(students[i]);
        return prettyGoodStudents;
    }

    vector<Student> getGoodStudents(){
        vector<Student> goodStudents;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() >= 7.0 && students[i].getGrade() < 8.5)
                goodStudents.push_back(students[i]);
        return goodStudents;
    }

    vector<Student> getAverageStudents(){
        vector<Student> averageStudents;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() >= 5.0 && students[i].getGrade() < 7.0)
                averageStudents.push_back(students[i]);
        return averageStudents;
    }

    vector<Student> getBelowAverageStudents(){
        vector<Student> belowAverageStudents;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() < 5.0)
                belowAverageStudents.push_back(students[i]);
        return belowAverageStudents;
    }

    int passingStudents(){
        int passing = 0;
        for(int i = 0; i < students.size(); i++)
            if(students[i].getGrade() >= 5.0)
                passing++;
        return passing;
    }

    int unpassingStudents(){
        return students.size() - passingStudents();
    }

    void sortByNameIncrease(){
        for(int i = 0; i < students.size() - 1; i++)
            for(int j = i + 1; j < students.size(); j++)
                if(students[i].getFullname() > students[j].getFullname())
                    swap(students[i], students[j]);
    }

    void sortByNameDecrease(){
        for(int i = 0; i < students.size() - 1; i++)
            for(int j = i + 1; j < students.size(); j++)
                if(students[i].getFullname() < students[j].getFullname())
                    swap(students[i], students[j]);
    }

    void sortByGradeIncrease(){
        for(int i = 0; i < students.size() - 1; i++)
            for(int j = i + 1; j < students.size(); j++)
                if(students[i].getGrade() > students[j].getGrade())
                    swap(students[i], students[j]);
    }

    void sortByGradeDecrease(){
        for(int i = 0; i < students.size() - 1; i++)
            for(int j = i + 1; j < students.size(); j++)
                if(students[i].getGrade() < students[j].getGrade())
                    swap(students[i], students[j]);
    }

    void saveToFile(string fileName){
        ofstream fout(fileName);
        if(fout.is_open()){
            fout << courseCode << endl << courseName << endl;
            for (int i = 0; i < students.size(); i++){
                if(i != students.size() - 1)
                    fout << students[i].getStudentId() << endl << students[i].getGrade() << endl << students[i].getFullname() << endl;
                else
                    fout << students[i].getStudentId() << endl << students[i].getGrade() << endl << students[i].getFullname();
            }
            fout.close();
        }
    }

    void readFromFile(string fileName){
        ifstream fin(fileName);
        string id, name;
        double score;

        if(fin.is_open()){
            students.clear();
            getline(fin, courseCode);
            getline(fin, courseName);

            while(getline(fin, id)){
                if (id.empty())
                    break;

                fin >> score;
                fin.ignore();
                getline(fin, name);

                students.push_back(Student(id, score, name));
            }
            fin.close();
        }
    }

    void printStudents(){
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl << endl;
        cout << "Students:" << endl;
        for (int i = 0; i < students.size(); i++){
            cout << "- - - - - - - - - - - -" << endl;
            cout << "Student " << i+1 << endl;
            students[i].Output();
        }
        cout << "- - - - - - - - - - - -" << endl;
    }
};
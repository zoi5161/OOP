#include "QuanLy.h"

QuanLy::QuanLy(){
    this -> name = "N/A";
    this -> start = 0;
    this -> salary = 0;
    this -> factorPosition = 0.0;
    this -> bonus = 0;
}

QuanLy::QuanLy(const string &name, int start, long long salary, double factorPosition, long long bonus){
    this -> name = name;
    this -> start = start;
    this -> salary = salary;
    this -> factorPosition = factorPosition;
    this -> bonus = bonus;
}

QuanLy::QuanLy(const string &name, int start){
    this -> name = name;
    this -> start = start;
    this -> salary = 0;
    this -> factorPosition = 0.0;
    this -> bonus = 0;
}

QuanLy::QuanLy(const string &name){
    this -> name = name;
    this -> start = 0;
    this -> salary = 0;
    this -> factorPosition = 0.0;
    this -> bonus = 0;
}

QuanLy::QuanLy(const QuanLy &other){
    this -> name = other.name;
    this -> start = other.start;
    this -> salary = other.salary;
    this -> factorPosition = other.factorPosition;
    this -> bonus = other.bonus;
}

long long QuanLy::calculateSalary(){
    return salary * factorPosition + bonus;
}

void QuanLy::input(){
    NhanVien::input();
    cout << "Enter the factor of position: ";
    cin >> factorPosition;
    cout << "Enter the bonus: ";
    cin >> bonus;
}

void QuanLy::output(){
    NhanVien::output();
    cout << "The factor of position: " << factorPosition << endl;
    cout << "The bonus: " << bonus << endl << endl;
}

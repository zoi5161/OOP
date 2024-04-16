#include "VanPhong.h"

VanPhong::VanPhong(){
    this -> name = "N/A";
    this -> start = 0;
    this -> salary = 0;
    this -> numDay = 0;
    this -> subsidy = 0;
}

VanPhong::VanPhong(const string &name, int start, long long salary, int numDay, long long subsidy){
    this -> name = name;
    this -> start = start;
    this -> salary = salary;
    this -> numDay = numDay;
    this -> subsidy = subsidy;
}

VanPhong::VanPhong(const string &name, int start){
    this -> name = name;
    this -> start = start;
    this -> salary = 0;
    this -> numDay = 0;
    this -> subsidy = 0;
}

VanPhong::VanPhong(const string &name){
    this -> name = name;
    this -> start = 0;
    this -> salary = 0;
    this -> numDay = 0;
    this -> subsidy = 0;
}

VanPhong::VanPhong(const VanPhong &other){
    this -> name = other.name;
    this -> start = other.start;
    this -> salary = other.salary;
    this -> numDay = other.numDay;
    this -> subsidy = other.subsidy;
}

long long VanPhong::calculateSalary() {
    return salary + numDay * 100000 + subsidy;
}

void VanPhong::input(){
    NhanVien::input();
    cout << "Enter the number of working days: ";
    cin >> numDay;
    cout << "Enter the subsidy: ";
    cin >> subsidy;
}

void VanPhong::output() {
    NhanVien::output();
    cout << "The number of working days: " << numDay << endl;
    cout << "The subsidy: " << subsidy << endl << endl;
}

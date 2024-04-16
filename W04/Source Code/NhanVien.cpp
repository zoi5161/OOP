#include "NhanVien.h"

NhanVien::NhanVien(){
    this -> name = "N/A";
    this -> start = 0;
    this -> salary = 0;
}

NhanVien::NhanVien(const string &name, int start, long long salary){
    this -> name = name;
    this -> start = start;
    this -> salary = salary;
}

NhanVien::NhanVien(const string &name, int start){
    this -> name = name;
    this -> start = start;
    this -> salary = 0;
}

NhanVien::NhanVien(const string &name){
    this -> name = name;
    this -> start = 0;
    this -> salary = 0;
}

NhanVien::NhanVien(const NhanVien &other){
    this -> name = other.name;
    this -> start = other.start;
    this -> salary = other.salary;
}

string NhanVien::getName(){
    return name;
}

void NhanVien::input(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter the start year: ";
    cin >> start;
    cout << "Enter the basic salary: ";
    cin >> salary;
}

void NhanVien::output(){
    cout << "Name: " << name << endl;
    cout << "The start year: " << start << endl;
    cout << "Salary: " << salary << endl;
}
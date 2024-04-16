#include "SanXuat.h"

SanXuat::SanXuat(){
    this -> name = "N/A";
    this -> start = 0;
    this -> salary = 0;
    this -> numProduct = 0;
}

SanXuat::SanXuat(const string &name, int start, long long salary, int numProduct){
    this -> name = name;
    this -> start = start;
    this -> salary = salary;
    this -> numProduct = numProduct;
}

SanXuat::SanXuat(const string &name, int start){
    this -> name = name;
    this -> start = start;
    this -> salary = 0;
    this -> numProduct = 0;
}

SanXuat::SanXuat(const string &name){
    this -> name = name;
    this -> start = 0;
    this -> salary = 0;
    this -> numProduct = 0;
}

SanXuat::SanXuat(const SanXuat &other){
    this -> name = other.name;
    this -> start = other.start;
    this -> salary = other.salary;
    this -> numProduct = other.numProduct;
}

long long SanXuat::calculateSalary(){
    return salary + numProduct * 100000;
}

void SanXuat::input(){
    NhanVien::input();
    cout << "Enter the number of products: ";
    cin >> numProduct;
}

void SanXuat::output(){
    NhanVien::output();
    cout << "The number of products: " << numProduct << endl << endl;
}

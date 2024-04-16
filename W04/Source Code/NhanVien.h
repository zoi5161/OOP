#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

class NhanVien{
protected:
    string name;
    int start;
    long long salary;
public:
    NhanVien();
    NhanVien(const string &name, int start, long long salary);
    NhanVien(const string &name, int start);
    NhanVien(const string &name);
    NhanVien(const NhanVien &other);

    virtual long long calculateSalary() = 0;
    string getName();
    void input();
    void output();
};

#endif
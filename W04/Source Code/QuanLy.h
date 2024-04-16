#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

class QuanLy : public NhanVien{
private:
    double factorPosition;
    long long bonus;
public:
    QuanLy();
    QuanLy(const string &name, int start, long long salary, double factorPosition, long long bonus);
    QuanLy(const string &name, int start);
    QuanLy(const string &name);
    QuanLy(const QuanLy &other);

    long long calculateSalary();
    void input();
    void output();
};

#endif
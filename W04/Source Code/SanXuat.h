#ifndef SANXUAT_h
#define SANXUAT_h

#include "NhanVien.h"

class SanXuat : public NhanVien{
private:
    int numProduct;
public:
    SanXuat();
    SanXuat(const string &name, int start, long long salary, int numProduct);
    SanXuat(const string &name, int start);
    SanXuat(const string &name);
    SanXuat(const SanXuat &other);

    long long calculateSalary();
    void input();
    void output();
};

#endif
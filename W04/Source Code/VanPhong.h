#ifndef VANPHONG_h
#define VANPHONG_h

#include "NhanVien.h"

class VanPhong : public NhanVien{
private:
    int numDay;
    double subsidy;
public:
    VanPhong();
    VanPhong(const string &name, int start, long long salary, int numDay, long long subsidy);
    VanPhong(const string &name, int start);
    VanPhong(const string &name);
    VanPhong(const VanPhong &other);

    long long calculateSalary();
    void input();
    void output();
};

#endif
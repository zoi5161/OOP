#ifndef CONGTY_h
#define CONGTY_h

#include "VanPhong.h"
#include "SanXuat.h"
#include "QuanLy.h"
#include <vector>

class CongTy{
private:
    vector<VanPhong> Office;
    vector<SanXuat> Product;
    vector<QuanLy> Manage;
public:
    void addOffice(const VanPhong &nhan_vien);
    void printOffice();

    void addProduct(const SanXuat &nhan_vien);
    void printProduct();

    void addManage(const QuanLy &nhan_vien);
    void printManage();

    long long totalSalary();
    void findStaffByName(const string &name);
};

#endif
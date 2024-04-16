#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

class NhanVien{
protected:
    string ten;
    int namVaoLam;
    string ma;
    string ngaySinh;

public:
    NhanVien(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh);
    virtual ~NhanVien();

    string layMa() const;
    string layTen() const;  
    string layThangSinh() const;

    virtual void nhapThongTin();
    virtual void xuatThongTin() const;
    virtual long long tinhLuong() = 0;
};

#endif

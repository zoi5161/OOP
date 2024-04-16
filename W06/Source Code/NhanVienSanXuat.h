#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien{
private:
    double luongCoBan;
    int soSanPham;
public:
    NhanVienSanXuat(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh);
    
    void nhapThongTin();
    void xuatThongTin() const;
    long long tinhLuong();
};

#endif

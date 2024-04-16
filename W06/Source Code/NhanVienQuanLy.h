#ifndef NHANVIENQUANLY_H
#define NHANVIENQUANLY_H

#include "NhanVien.h"

class NhanVienQuanLy : public NhanVien{
private:
    double luongCoBan;
    double heSoChucVu;
    double thuong;
public:
    NhanVienQuanLy(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh);
    
    void nhapThongTin();
    void xuatThongTin() const;
    long long tinhLuong();
};

#endif

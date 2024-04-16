#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien{
private:
    double luongCoBan;
    int soNgayLamViec;
    double troCap;
public:
    NhanVienVanPhong(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh);

    void nhapThongTin();
    void xuatThongTin() const;
    long long tinhLuong();
};

#endif
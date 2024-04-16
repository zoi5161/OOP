#ifndef CONGTY_H
#define CONGTY_H

#include "NhanVien.h"
#include <vector>

class CongTy{
private:
    vector<NhanVien*> danhSachNhanVien;
public:
    CongTy();
    ~CongTy();

    void nhapDanhSachNhanVien();
    void xuatDanhSachNhanVien() const;
    long long tinhTongLuong() const;
    NhanVien* timNhanVienLuongCaoNhat() const;
    int demNhanVienSanXuat() const;
    int demNhanVienVanPhong() const;
    long long tinhLuongTrungBinh() const;
    void lietKeNhanVienLuongThapHon(long long gioiHanLuong) const;
    void timNhanVienTheoMa(const string& ma) const;
    void timNhanVienTheoTen(const string& ten) const;
    void demNhanVienTheoThangSinh(string thangSinh) const;
};

#endif

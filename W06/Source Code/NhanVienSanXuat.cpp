#include "NhanVienSanXuat.h"
#include <iostream>

NhanVienSanXuat::NhanVienSanXuat(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh) : NhanVien(ten, namVaoLam, ma, ngaySinh), luongCoBan(0.0), soSanPham(0){}

void NhanVienSanXuat::nhapThongTin(){
    NhanVien::nhapThongTin();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void NhanVienSanXuat::xuatThongTin() const{
    NhanVien::xuatThongTin();
    cout << "Loai nhan vien: San xuat\n";
}

long long NhanVienSanXuat::tinhLuong(){
    return luongCoBan + soSanPham * 2000;
}

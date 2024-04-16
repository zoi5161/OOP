#include "NhanVienQuanLy.h"

NhanVienQuanLy::NhanVienQuanLy(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh) : NhanVien(ten, namVaoLam, ma, ngaySinh), luongCoBan(0.0), heSoChucVu(0.0), thuong(0.0){}

void NhanVienQuanLy::nhapThongTin(){
    NhanVien::nhapThongTin();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap he so chuc vu: ";
    cin >> heSoChucVu;
    cout << "Nhap thuong: ";
    cin >> thuong;
}

void NhanVienQuanLy::xuatThongTin() const{
    NhanVien::xuatThongTin();
    cout << "Loai nhan vien: Quan ly\n";
}

long long NhanVienQuanLy::tinhLuong(){
    return luongCoBan * heSoChucVu + thuong;
}

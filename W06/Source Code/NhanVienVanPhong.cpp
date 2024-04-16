#include "NhanVienVanPhong.h"

NhanVienVanPhong::NhanVienVanPhong(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh) : NhanVien(ten, namVaoLam, ma, ngaySinh), luongCoBan(0.0), soNgayLamViec(0), troCap(0.0) {}

void NhanVienVanPhong::nhapThongTin(){
    NhanVien::nhapThongTin();
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
    cout << "Nhap tro cap: ";
    cin >> troCap;
}

void NhanVienVanPhong::xuatThongTin() const{
    NhanVien::xuatThongTin();
    cout << "Loai nhan vien: Van phong\n";
}

long long NhanVienVanPhong::tinhLuong(){
    return luongCoBan + soNgayLamViec * 100000 + troCap;
}

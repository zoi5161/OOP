#include "CongTy.h"

int main(){
    CongTy congty;
    string key;

    congty.nhapDanhSachNhanVien();

    cout << endl << "- - - - - - - - - - - - -" << endl;
    cout << "Danh sach nhan vien:" << endl << endl;
    congty.xuatDanhSachNhanVien();

    cout << "- - - - - - - - - - - - -" << endl;
    cout << "So nhan vien san xuat la: " << congty.demNhanVienSanXuat() << endl;
    cout << "So nhan vien van phong la: " << congty.demNhanVienVanPhong() << endl;
    cout << "Luong trung binh cua cong ty la: " << congty.tinhLuongTrungBinh() << endl;

    cout << endl << "- - - - - - - - - - - - -" << endl;
    congty.lietKeNhanVienLuongThapHon(3000000);

    cout << endl << "- - - - - - - - - - - - -" << endl;
    cout << "Nhap ma nhan vien ban muon tim: ";
    cin >> key;
    congty.timNhanVienTheoMa(key);

    cout << endl << "Nhap ho ten nhan vien ban muon tim: ";
    cin >> key;
    congty.timNhanVienTheoTen(key);

    cout << endl << "- - - - - - - - - - - - -" << endl;
    congty.demNhanVienTheoThangSinh("5");
    
    return 0;
}
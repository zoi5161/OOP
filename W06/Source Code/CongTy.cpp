#include "CongTy.h"
#include "NhanVien.h"
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include "NhanVienQuanLy.h"

CongTy::CongTy(){}

CongTy::~CongTy(){
    for(int i = 0; i < danhSachNhanVien.size(); i++)
        delete danhSachNhanVien[i];
}

void CongTy::nhapDanhSachNhanVien(){
    int soLuong;
    cout << "Nhap so luong nhan vien: ";
    cin >> soLuong;

    for(int i = 0; i < soLuong; i++){
        char loaiNhanVien;
        cout << endl << "Nhap loai nhan vien (V: Van phong, S: San xuat, Q: Quan ly): ";
        cin >> loaiNhanVien;

        NhanVien* nv = nullptr;

        if(loaiNhanVien == 'V' || loaiNhanVien == 'v')
            nv = new NhanVienVanPhong("", 0, "", "");
        else if(loaiNhanVien == 'S' || loaiNhanVien == 's')
            nv = new NhanVienSanXuat("", 0, "", "");
        else if(loaiNhanVien == 'Q' || loaiNhanVien == 'q')
            nv = new NhanVienQuanLy("", 0, "", "");
        else{
            cout << "Nhap sai. Vui long nhap lai." << endl;
            i--;
            continue;
        }

        nv -> nhapThongTin();
        danhSachNhanVien.push_back(nv);
    }
}

void CongTy::xuatDanhSachNhanVien() const{
    for(int i = 0; i < danhSachNhanVien.size(); i++){
        danhSachNhanVien[i] -> xuatThongTin();
        cout << "Luong: " << danhSachNhanVien[i] -> tinhLuong() << endl;
        if(i != danhSachNhanVien.size() - 1)
            cout << endl;
    }
}

long long CongTy::tinhTongLuong() const{
    long long tongLuong = 0;
    for(int i = 0; i < danhSachNhanVien.size(); i++)
        tongLuong += danhSachNhanVien[i] -> tinhLuong();
    return tongLuong;
}

NhanVien* CongTy::timNhanVienLuongCaoNhat() const{
    if(danhSachNhanVien.empty())
        return nullptr;

    NhanVien* nhanVienLuongCaoNhat = danhSachNhanVien[0];
    long long luongCaoNhat = nhanVienLuongCaoNhat -> tinhLuong();

    for(int i = 0; i < danhSachNhanVien.size(); i++){
        long long luong = danhSachNhanVien[i] -> tinhLuong();
        if(luong > luongCaoNhat){
            luongCaoNhat = luong;
            nhanVienLuongCaoNhat = danhSachNhanVien[i];
        }
    }

    return nhanVienLuongCaoNhat;
}

int CongTy::demNhanVienSanXuat() const{
    int dem = 0;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
        if (dynamic_cast<NhanVienSanXuat*>(danhSachNhanVien[i]) != nullptr)
            dem++;
    return dem;
}

int CongTy::demNhanVienVanPhong() const{
    int dem = 0;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
        if (dynamic_cast<NhanVienVanPhong*>(danhSachNhanVien[i]) != nullptr)
            dem++;
    return dem;
}

long long CongTy::tinhLuongTrungBinh() const{
    if (danhSachNhanVien.empty())
        return 0.0;

    long long tongLuong = 0.0;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
        tongLuong += danhSachNhanVien[i] -> tinhLuong();

    return tongLuong / danhSachNhanVien.size();
}

void CongTy::lietKeNhanVienLuongThapHon(long long gioiHanLuong) const{
    cout << "Cac nhan vien co luong thap hon " << gioiHanLuong << " la:" << endl << endl;
    for (int i = 0; i < danhSachNhanVien.size(); i++){
        if (danhSachNhanVien[i] -> tinhLuong() < gioiHanLuong){
            danhSachNhanVien[i] -> xuatThongTin();
            cout << "Luong: " << danhSachNhanVien[i] -> tinhLuong() << endl << endl;
        }
    }
}

void CongTy::timNhanVienTheoMa(const string& ma) const{
    bool haven = false;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
        if (danhSachNhanVien[i] -> layMa() == ma){
            danhSachNhanVien[i] -> xuatThongTin();
            haven = true;
            break;
        }
    if(!haven)
        cout << "Khong co nhan vien nao co ma " << ma << endl;
}

void CongTy::timNhanVienTheoTen(const string& ten) const{
    bool haven = false;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
        if (danhSachNhanVien[i] -> layTen() == ten){
            danhSachNhanVien[i] -> xuatThongTin();
            haven = true;
            break;
        }
    if(!haven)
        cout << "Khong co nhan vien nao co ten " << ten << endl;
}

void CongTy::demNhanVienTheoThangSinh(string thangSinh) const{
    bool haven = false;
    int cnt = 0;
    string thangSinhFormat = "0";
    thangSinhFormat += thangSinh;

    for (int i = 0; i < danhSachNhanVien.size(); i++)
        if (danhSachNhanVien[i] -> layThangSinh() == thangSinh || danhSachNhanVien[i] -> layThangSinh() == thangSinhFormat){
            cnt++;
            haven = true;
        }
    if(!haven)
        cout << "Khong co nhan vien nao sinh thang " << thangSinh << endl;
    else
        cout << "Co " << cnt << " nhan vien sinh thang " << thangSinh << endl;
}
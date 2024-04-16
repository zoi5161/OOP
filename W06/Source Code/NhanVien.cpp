#include "NhanVien.h"

NhanVien::NhanVien(const string& ten, const int namVaoLam, const string& ma, const string& ngaySinh)
    : ten(ten), namVaoLam(namVaoLam), ma(ma), ngaySinh(ngaySinh){}

NhanVien::~NhanVien(){}

string NhanVien::layMa() const{
    return ma;
}

string NhanVien::layTen() const{
    return ten;
}

string NhanVien::layThangSinh() const{
    int cnt = 0;
    string thang = "";

    for(int i = 0; i < ngaySinh.length(); i++){
        if(ngaySinh[i] == '/' && cnt == 0)
            cnt++;
        else if(ngaySinh[i+1] != '/' && cnt == 1)
            thang += ngaySinh[i];
        else if(cnt == 1){
            thang += ngaySinh[i];
            break;
        }
    }

    return thang;
}

void NhanVien::nhapThongTin(){
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, ten);

    cout << "Nhap nam vao lam: ";
    cin >> namVaoLam;

    cout << "Nhap ma nhan vien: ";
    cin >> ma;

    cout << "Nhap ngay sinh (DD/MM/YYYY): ";
    cin >> ngaySinh;
}

void NhanVien::xuatThongTin() const{
    cout << "Ho va ten: " << ten << endl;
    cout << "Nam vao lam: " << namVaoLam << endl;
    cout << "Ma nhan vien: " << ma << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}

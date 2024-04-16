#include "CongTy.h"

int main() {
    CongTy cong_ty;

    VanPhong Of1("Nguyen Van Thuy", 2020, 5000000, 20, 300000);
    VanPhong Of2("Tran Thi Lan", 2019, 6000000, 22, 350000);
    cong_ty.addOffice(Of1);
    cong_ty.addOffice(Of2);

    SanXuat Pro1("Le Van Cao", 2021, 4000000, 100);
    SanXuat Pro2("Hoang Thi Dung", 2018, 4500000, 120);
    cong_ty.addProduct(Pro1);
    cong_ty.addProduct(Pro2);

    QuanLy Mana1("Tran Van Tu", 2017, 7000000, 1.5, 1000000);
    QuanLy Mana2("Pham Minh Phuong", 2016, 8000000, 1.8, 1500000);
    cong_ty.addManage(Mana1);
    cong_ty.addManage(Mana2);

    cong_ty.printOffice();
    cong_ty.printProduct();
    cong_ty.printManage();

    cout << "- - - - - - - - - - - -" << endl;
    cout << "Total salary of company: " << cong_ty.totalSalary() << endl;

    cout << "- - - - - - - - - - - -" << endl;
    cout << "Result of finding 'Tran Van Tu': " << endl;
    cong_ty.findStaffByName("Tran Van Tu");

    cout << "Result of finding 'Tran Gia Bao': " << endl;
    cong_ty.findStaffByName("Tran Gia Bao");
    return 0;
}

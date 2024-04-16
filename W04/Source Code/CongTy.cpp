#include "CongTy.h"

void CongTy::addOffice(const VanPhong &nhan_vien){
    Office.push_back(nhan_vien);
}

void CongTy::printOffice(){
    cout << endl << "- - - - - - - - - - - -" << endl;
    cout << "The list of office staff:" << endl;
    for (int i = 0; i < Office.size(); i++)
        Office[i].output();
}

void CongTy::addProduct(const SanXuat &nhan_vien){
    Product.push_back(nhan_vien);
}

void CongTy::printProduct(){
    cout << endl << "- - - - - - - - - - - -" << endl;
    cout << "The list of product staff:" << endl;
    for (int i = 0; i < Product.size(); i++)
        Product[i].output();
}

void CongTy::addManage(const QuanLy &nhan_vien){
    Manage.push_back(nhan_vien);
}

void CongTy::printManage(){
    cout << endl << "- - - - - - - - - - - -" << endl;
    cout << "The list of manage staff:" << endl;
    for(int i = 0; i < Manage.size(); i++)
        Manage[i].output();
}

long long CongTy::totalSalary(){
    long long total = 0;

    for(int i = 0; i < Office.size(); i++)
        total += Office[i].calculateSalary();

    for(int i = 0; i < Product.size(); i++)
        total += Product[i].calculateSalary();
    
    for(int i = 0; i < Manage.size(); i++)
        total += Manage[i].calculateSalary();
    
    return total;
}

void CongTy::findStaffByName(const string &name){
    bool find = false;
    for(int i = 0; i < Office.size(); i++)
        if(Office[i].getName() == name){
            Office[i].output();
            find = true;
        }
    
    for(int i = 0; i < Product.size(); i++)
        if(Product[i].getName() == name){
            Product[i].output();
            find = true;
        }

    for(int i = 0; i < Manage.size(); i++)
        if(Manage[i].getName() == name){
            Manage[i].output();
            find = true;
        }
    
    if(find == false)
        cout << "There is no one named " << name << endl << endl;
}
#include "Store.h"

Order::Order(string orderCode, string customName, string phoneNumber, long long totalPrice){
    this -> orderCode = orderCode;
    this -> customName = customName;
    this -> phoneNumber = phoneNumber;
    this -> totalPrice = totalPrice;
    paymentMethod = NULL;
}

Order::~Order(){
    for(int i = 0; i < productList.size(); i++)
        delete productList[i];
    if (paymentMethod){
        delete paymentMethod;
        paymentMethod = nullptr;
    }
}

long long Order::getTotalPrice(){
    return totalPrice;
}

void Order::addProduct(Product *p){
    productList.push_back(p);
    totalPrice += p -> price;
}

void Order::pay(){
    string choice;
    cout << "Bạn muốn thanh toán bằng:" << endl;
    cout << "1. Tiền mặt" << endl;
    cout << "2. Momo" << endl;
    cout << "3. ATM" << endl;

    cout << endl << "Lựa chọn của bạn là: ";
    cin >> choice;

    if(choice == "1"){
        paymentMethod = new CashPayment();
        paymentMethod -> pay(totalPrice);
    }
    else if(choice == "2"){
        paymentMethod = new Momo();
        paymentMethod -> pay(totalPrice);
    }
    else if(choice == "3"){
        paymentMethod = new ATM();
        paymentMethod -> pay(totalPrice);
    }
}
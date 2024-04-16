#ifndef STORE_h
#define STORE_h

#include <iostream>
#include <vector>

using namespace std;

class Product{
    public:
        string productID;
        int product;
        long long price;
        int inventoryNumber;
        Product(string productID, int product, int price, int inventoryNumber) : productID(productID), product(product), price(price), inventoryNumber(inventoryNumber){};
};

class PaymentMethod{
    public:
        virtual void pay(long long p) = 0;
        virtual ~PaymentMethod(){};
};

class Order{
    private:
        string orderCode;
        string customName;
        string phoneNumber;
        string address;
        vector <Product*> productList;
        long long totalPrice;
        PaymentMethod* paymentMethod;
    public:
        Order(string orderCode, string customName, string phoneNumber, long long totalPrice);
        ~Order();
        long long getTotalPrice();
        void addProduct(Product *p);
        void pay();
};

class CashPayment : public PaymentMethod{
    public:
        void pay(long long p){
            cout << "Đã thanh toán " << p << " bằng tiền mặt";
        }
};

class Momo : public PaymentMethod{
    public:
        void pay(long long p){
            cout << "Đã thanh toán " << p << " bằng ví Momo";
        }
};

class ATM : public PaymentMethod{
    public:
        void pay(long long p){
            cout << "Đã thanh toán " << p << " bằng thẻ ATM";
        }
};

#endif

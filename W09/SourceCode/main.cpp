#include "Store.h"
#include "State.h"
#include "Dragon.h"

int main(){
    // Bài 1
    cout << "- - - - - - - - - - - -" << endl;
    Product* product1 = new Product("PS4", 1, 1000, 10);
    Product* product2 = new Product("PS5", 2, 500, 20);

    Order* order = new Order("O001", "Khach Hang 1", "123456789", 0);

    order -> addProduct(product1);
    order -> addProduct(product2);
    
    cout << "Đã thêm mặt hàng PS4" << endl;
    cout << "Đã thêm mặt hàng PS5" << endl << endl;
    cout << "Tổng giá trị đơn hàng: " << order -> getTotalPrice() << " đồng" << endl << endl;

    order -> pay();

    delete product1;
    delete product2;

    cout << endl << endl;
    cout << "- - - - - - - - - - - -" << endl;

    // Bài 2
    string name;
    int level;
    double atk;
    double hp;
    double def;

    cin.ignore();
    cout << "Nhập tên rồng: ";
    getline(cin, name);

    cout << "Nhập level của rồng: ";
    cin >> level;

    cout << "Nhập máu của rồng: ";
    cin >> hp;

    cout << "Nhập sức tấn công của rồng: ";
    cin >> atk;

    cout << "Nhập sức phòng thủ của rồng: ";
    cin >> def;

    cout << endl << endl;

    Dragon dragon(name, level, hp, atk, def);

    dragon.display();

    dragon.setState(new NormalState());
    dragon.displayDragonState();
    dragon.attackState(dragon);
    dragon.moveState(dragon);
    cout << "Lực chiến: " << dragon.calculatePower(dragon) << "\n";

    cout << endl;
    dragon.setState(new RageState());
    dragon.displayDragonState();
    dragon.attackState(dragon);
    dragon.moveState(dragon);
    cout << "Lực chiến: " << dragon.calculatePower(dragon) << "\n";

    cout << endl;
    dragon.setState(new DefenseState());
    dragon.displayDragonState();
    dragon.attackState(dragon);
    dragon.moveState(dragon);
    cout << "Lực chiến: " << dragon.calculatePower(dragon) << "\n";

    return 0;
}

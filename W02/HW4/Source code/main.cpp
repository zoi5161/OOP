#include "Student.h"

int main()
{
    system("clear");
    // Default constructor
    Student student1;

    // Full parameter constructor
    Student student2("22127034", 3.9, "Tran Gia Bao", "Lam Van Ben");
    cout << endl << "Full parameter constructor Student student2(22127034, 3.9, Tran Gia Bao, Lam Van Ben): " << endl << student2;

    // Copy constructor
    Student student3 = (student2);
    cout << endl << "Copy parameter constructor Student student3 = (student2): " << endl << student3;

    // >> <<
    Student student;
    cout << endl << ">> << constructor: " << endl;
    cin >> student;
    cout << endl;
    cout << student;
    return 0;
}

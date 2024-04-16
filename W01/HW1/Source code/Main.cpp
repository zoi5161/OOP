#include "Fraction.cpp"

int main(){
    Fraction Frac1, Frac2, result;
    int a, b;
    char conti = ' ', choice = '1';

    cout << "Enter the numerator of first fraction: ";
    cin >> a;
    cout << "Enter the denominator of first fraction: ";
    cin >> b;

    if(b == 0)
    {
        cout << "Error";
        return 0;
    }

    if(a < 0 && b < 0){
        a = abs(a);
        b = abs(b);
    }
    else if(b < 0){
        a = -a;
        b = abs(b);
    }

    Frac1.enter(a, b);
    Frac1.print();
    

    cout << endl << "Enter the numerator of second fraction: ";
    cin >> a;
    cout << "Enter the denominator of second fraction: ";
    cin >> b;

    if(b == 0)
    {
        cout << "Error";
        return 0;
    }

    if(a < 0 && b < 0){
        a = abs(a);
        b = abs(b);
    }
    else if(b < 0){
        a = -a;
        b = abs(b);
    }
    
    Frac2.enter(a, b);
    Frac2.print();

    cout << endl;
    while(choice != '5'){
        if(choice > '0' && choice < '6'){
        cout << "Options (1 -> 5): " << endl;
        cout << "1. Summation" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl << endl;
        }
        
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1')
            result = Frac1.add(Frac2);
        else if(choice == '2')
            result = Frac1.sub(Frac2);
        else if(choice == '3')
            result = Frac1.multi(Frac2);
        else if(choice == '4')
            result = Frac1.divide(Frac2);
        else if(choice == '5')
            break;
        else
        {
            cout << "Please enter again. Options from 1 to 5: ";
            continue;
        }
        result.print();
        while(conti != 'Y' && conti != 'N'){
            cout << "Do you want to continue (Y/N): ";
            cin >> conti;
            if(conti == 'Y')
            {
                conti = ' ';
                break;
            }
            else if(conti == 'N')
                choice = '5';
        }
        cout << endl;
    }
    return 0;
}
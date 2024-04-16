#include "Date.cpp"

int main(){
    system("clear");
    Date today, another;
    int day = -1, month = -1, year = -1, n;
    string choice = "1", skip = "";

    cout << "Day: ";
    while(1)
    {
        cin >> day;
        if(day < 1 || day > 31)
            cout << "Invalid date. Please enter again: " << endl;
        else 
            break;
    }
    
    cout << "Month: ";
    while(1)
    {
        cin >> month;
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(day < 1 || day > 31)
                cout << "Invalid month. Please enter again: " << endl;
            else
                break;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day < 1 || day > 30)
                cout << "Invalid month. Please enter again: " << endl;
            else
                break;
        }
        else if(month == 2)
        {
            if(day < 1 || day > 29)
                cout << "Invalid month. Please enter again: " << endl;
            else
                break;
        }
        else
            cout << "Invalid month. Please enter again: " << endl;
    }

    cout << "Year: ";
    while(1)
    {
        cin >> year;
        if(month == 2 && day == 29)
        {
            if((year % 400 == 0) || ((year % 100 == 0) && (year % 4 == 0)))
                break;
            else
                cout << "Invalid year. Please enter again: " << endl;
        }
        else if(year < 0)
            cout << "Invalid year. Please enter again: " << endl;
        else 
            break;
    }

    today.Input(day, month, year);
    cout << endl;

    while(1)
    {
        if(choice >= "1" && choice <= "8")
        {
            today.Output();
            cout << "- - - - Options - - - -" << endl;
            cout << "1. Print day" << endl;
            cout << "2. Increase 1 day" << endl;
            cout << "3. Increase n days" << endl;
            cout << "4. Decrease 1 day" << endl;
            cout << "5. Decrease n days" << endl;
            cout << "6. Compare with an orther day" << endl;
            cout << "7. Exit" << endl << endl;
            cout << "Your choice: ";
        }

        cin >> choice;
        if(choice == "1")
            today.Output();
        else if(choice == "2")
            today.IncreaseOneDay();
        else if(choice == "3")
        {
            cout << "Enter the number of days: ";
            cin >> n;
            while(n < 0)
            {
                cout << "Invalid. Please enter again (n > 0): ";
                cin >> n;
            }
            today.IncreaseNDays(n);
        }
        else if(choice == "4")
            today.DecreaseOneDay();
        else if(choice == "5")
        {
            cout << "Enter the number of days: ";
            cin >> n;
            while(n < 0)
            {
                cout << "Invalid. Please enter again (n > 0): ";
                cin >> n;
            }
            today.DecreaseNDays(n);
        }
        else if(choice == "6")
        {
            cout << endl << "Enter another day" << endl;
            cout << "Day: ";
            while(1)
            {
                cin >> day;
                if(day < 1 || day > 31)
                    cout << "Invalid date. Please enter again: " << endl;
                else 
                    break;
            }
            
            cout << "Month: ";
            while(1)
            {
                cin >> month;
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    if(day < 1 || day > 31)
                        cout << "Invalid month. Please enter again: " << endl;
                    else
                        break;
                }
                else if(month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if(day < 1 || day > 30)
                        cout << "Invalid month. Please enter again: " << endl;
                    else
                        break;
                }
                else if(month == 2)
                {
                    if(day < 1 || day > 29)
                        cout << "Invalid month. Please enter again: " << endl;
                    else
                        break;
                }
                else
                    cout << "Invalid month. Please enter again: " << endl;
            }

            cout << "Year: ";
            while(1)
            {
                cin >> year;
                if(month == 2 && day == 29)
                {
                    if((year % 400 == 0) || ((year % 100 == 0) && (year % 4 == 0)))
                        break;
                    else
                        cout << "Invalid year. Please enter again: " << endl;
                }
                else if(year < 0)
                    cout << "Invalid year. Please enter again: " << endl;
                else 
                    break;
            }

            another.Input(day, month, year);
            cout << endl;
            another.Output();

            if(today.Compare(another) == 1)
                cout << "Result: 1 (It is bigger)" << endl;
            else if(today.Compare(another) == -1)
                cout << "Result: -1 (It is smaller)" << endl;
            else
                cout << "Result: 0 (This is the same day)" << endl;
        }
        else if(choice == "7")
            break;
        else
        {
            choice = "0";
            cout << "Invalid choice. Please enter again (1 -> 7): ";
            continue;
        }

        if(choice >= "2" && choice <= "5")
            today.Output();
        
        cout << "Do you want to continue (Y/N): ";
        while(1)
        {
            cin >> skip;
            if(skip == "Y" || skip == "y")
            {
                system("clear");
                break;
            }
            else if(skip == "N" || skip == "n")
            {
                system("clear");
                return 0;
            }
            else
                cout << "Invalid choice. Please enter again (Y/N): ";
        }
        cout << endl;
    }
    system("clear");
    return 0;
}
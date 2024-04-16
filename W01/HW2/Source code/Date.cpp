#include "Date.h"

void Date::Input(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

void Date::Output(){
    cout << "Date: ";
    if(day < 10) 
        cout << 0 << day << '/';
    else
        cout << day << '/';
    
    if(month < 10)
        cout << 0 << month << '/';
    else
        cout << month << '/';
    
    if(year < 10)
        cout << "000" << year << endl;
    else if(year < 100)
        cout << "00" << year << endl;
    else if(year < 1000)
        cout << 0 << year << endl;
    else
        cout << year << endl;
    cout << endl;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::getMaxDayInMonth(int m, int y){
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
        return 29;
    return daysInMonth[m];
}

void Date::IncreaseOneDay(){
    int mon = this -> month;
    if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
    {
        if(this -> day == 31)
        {
            this -> day = 1;
            if(mon == 12)
            {
                this -> month = 1;
                (this -> year)++;
            }
            else
                (this -> month)++;
        }
        else
            (this -> day)++;
    }
    else if(mon == 4 || mon == 6 || mon == 9 || mon == 11)
    {
        if(this -> day == 30)
        {
            this -> day = 1;
            (this -> month)++;
        }
        else
            (this -> day)++;
    }
    else
    {
        if(((this -> year) % 400 == 0) || (((this -> year) % 100 == 0) && ((this -> year) % 4 == 0)))
        {
            if(this -> day == 29)
            {
                this -> day = 1;
                this -> month = 3;
            }
            else
                (this -> day)++;
        }
        else
        {
            if(this -> day == 28)
            {
                this -> day = 1;
                this -> month = 3;
            }
            else
                (this -> day)++;
        }
    }
}

void Date::IncreaseNDays(int n){
    for (int i = 0; i < n; i++) 
    {
        day++;
        if(day > getMaxDayInMonth(month, year)) 
        {
            day = 1;
            month++;
            if(month > 12) 
            {
                month = 1;
                year++;
            }
        }
    }
}

void Date::DecreaseOneDay(){
    int mon = this -> month;
    if(mon == 5 || mon == 7 || mon == 10 || mon == 12)
    {
        if(this -> day == 1)
        {
            this -> day = 30;
            (this -> month)--;
        }
        else
            (this -> day)--;
    }
    else if(mon == 1 || mon ==  2|| mon == 4 || mon == 6 || mon == 8 || mon == 9 || mon == 11)
    {
        if(this -> day == 1)
        {
            this -> day = 31;
            if(this -> month == 1)
            {
                this -> month = 12;
                (this -> year)--;
            }
            else
                (this -> month)--;
        }
        else
            (this -> day)--;
    }
    else
    {
        if(((this -> year) % 400 == 0) || (((this -> year) % 100 == 0) && ((this -> year) % 4 == 0)))
        {
            if(this -> day == 1)
            {
                this -> day = 29;
                this -> month = 2;
            }
            else
                (this -> day)--;
        }
        else
        {
            if(this -> day == 1)
            {
                this -> day = 28;
                this -> month = 2;
            }
            else
                (this -> day)--;
        }
    }
}

void Date::DecreaseNDays(int n){
    for (int i = 0; i < n; i++) 
    {
        day--;
        if(day == 0) 
        {
            month--;
            if (month == 0) 
            {
                month = 12;
                year--;
            }
            day = getMaxDayInMonth(month, year);
        }
    }
}

int Date::Compare(Date another){
    if(this -> day < another.getDay())
        return -1;
    else if(this -> day > another.getDay())
        return 1;
    else
        return 0;
}
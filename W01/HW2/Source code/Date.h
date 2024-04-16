#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    void Input(int day, int month, int year);
    void Output();
    int getDay();
    int getMonth();
    int getYear();
    int getMaxDayInMonth(int m, int y);
    void IncreaseOneDay();
    void IncreaseNDays(int n);
    void DecreaseOneDay();
    void DecreaseNDays(int n);
    int Compare(Date another);
};
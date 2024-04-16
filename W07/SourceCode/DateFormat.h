#ifndef DATEFORMAT_h
#define DATEFORMAT_h

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class DateFormatException : public exception{
    public:
        const char* what() const throw(){
            return "Exception: Invalid date! \n";
        }
};

#endif

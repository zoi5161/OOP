#ifndef INTFORMAT_h
#define INTFORMAT_h

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IntegerFormatException : public exception{
    public:
        const char* what() const throw(){
            return "Exception: Invalid string! \n";
        }
};

#endif

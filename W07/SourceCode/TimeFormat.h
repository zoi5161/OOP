#ifndef TIME_h
#define TIME_h

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class TimeFormatException : public exception{
    public:
        const char* what() const throw(){
            return "Exception: Invalid time! \n";
        }
};

#endif

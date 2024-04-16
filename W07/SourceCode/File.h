#ifndef FILE_h
#define FILE_h

#include <iostream>
#include <exception>
#include <string>
#include <fstream>

using namespace std;

class FileNotFoundException : public exception{
    public:
        const char* what() const throw(){
            return "Exception: File doesn't exist\n";
        }
};

#endif

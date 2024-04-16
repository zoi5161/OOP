#ifndef ARRAY_h
#define ARRAY_h

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

class IndexOutOfRangeException : public exception{
    private:
        int index;
        int capacity;
    public:
        IndexOutOfRangeException(int index, int capacity){
            this -> index = index;
            this -> capacity = capacity;
        }
        const char* what() const throw(){
            stringstream stream;
            stream << "Exception: Index out of range" << endl;
            stream << "Detail: index = " << index << ", capacity = " << capacity << endl;
            return strdup(stream.str().c_str());
        }
};

class Array{
    private:
        int *arr;
        int size;
    public:
        Array();
        Array(int* arr, int size);
        ~Array();
        int getValueAt(int index) const;
};

#endif

#include "Array.h"

Array::Array(){
    this -> arr = nullptr;
    this -> size = 0;
}

Array::Array(int* arr, int size){
    this -> arr = new int[size];

    for (int i = 0; i < size; i++) 
        this -> arr[i] = arr[i];
    this -> size = size;
}

Array::~Array(){
    delete []arr;
}

int Array::getValueAt(int index) const{
    if (index < 0 || index >= size)
        throw IndexOutOfRangeException(index, size);
    return arr[index];
}
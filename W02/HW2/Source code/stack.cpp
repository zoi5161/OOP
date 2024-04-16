#include "stack.h"

Stack::Stack(int size){
    this->size = size;
    arr = new int[size];
    topIndex = -1;
}

Stack::~Stack(){
    delete[] arr;
}

bool Stack::isEmpty() const{
    return topIndex == -1;
}

bool Stack::isFull() const{
    return topIndex == size - 1;
}

void Stack::push(int value){
    if (!isFull())
        arr[++topIndex] = value;
    else
        cout << "Stack is full" << endl;
}

int Stack::pop(){
    if (!isEmpty())
        return arr[topIndex--];
    else
        cout << "Stack is empty" << endl;
}

int Stack::getTopValue() const{
    if (!isEmpty())
        return arr[topIndex];
    else
        cout << "Stack is empty" << endl;
}

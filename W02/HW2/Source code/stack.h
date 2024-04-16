#pragma once
#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int topIndex;
    int size;
public:
    Stack(int size);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(int value);
    int pop();
    int getTopValue() const;
};

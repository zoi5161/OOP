#ifndef STACK_h
#define STACK_h

#include <iostream>
#include <stdexcept>

using namespace std;

class Stack{
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int top;
public:
    Stack() : top(-1){}

    void push(int value){
        if(top == MAX_SIZE - 1)
            throw overflow_error("Stack is full");
        data[++top] = value;
    }

    void pop(){
        if(isEmpty())
            throw underflow_error("Stack is empty");
        --top;
    }

    int getTop() const{
        if(isEmpty())
            throw underflow_error("Stack is empty");
        return data[top];
    }

    bool isEmpty() const{
        return top == -1;
    }
};

#endif

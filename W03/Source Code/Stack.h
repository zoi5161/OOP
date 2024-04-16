#pragma once
#include <iostream>

using namespace std;

template <class T> class Stack{
private:
    T* data;
    int topIndex;
    int capacity;
public:
    Stack(int n);
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T &item);
    T pop();
    T getTop();
};

template <class T> Stack<T>::Stack(int n){
    capacity = n;
    data = new T[n];
    topIndex = -1;
}

template <class T> Stack<T>::~Stack(){
    delete[] data;
}

template <class T> void Stack<T>::clear(){
    topIndex = -1;
}

template <class T> bool Stack<T>::isFull(){
    return topIndex == capacity - 1;
}

template <class T> bool Stack<T>::isEmpty(){
    return topIndex == -1;
}

template <class T> void Stack<T>::push(const T &item){
    if (!isFull())
        data[++topIndex] = item;
    else
        return;
}

template <class T> T Stack<T>::pop(){
    if (!isEmpty())
        return data[topIndex--];
    else
        return T();
}

template <class T> T Stack<T>::getTop(){
    if (!isEmpty())
        return data[topIndex];
    else
        return T();
}
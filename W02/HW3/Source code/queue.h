#pragma once
#include <iostream>

using namespace std;

class Queue{
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;
public:
    Queue(int capacity);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int item);
    int dequeue();
    int getFrontValue() const;
};

#ifndef QUEUE_h
#define QUEUE_h

#include <iostream>
#include <stdexcept>

using namespace std;

class Queue{
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int front, rear;
public:
    Queue() : front(-1), rear(-1){}

    void enqueue(int value){
        if (isFull())
            throw overflow_error("Queue is full");

        if (isEmpty()){
            front = 0;
            rear = 0;
        }
        else
            rear = (rear + 1) % MAX_SIZE;
        data[rear] = value;
    }

    void dequeue(){
        if (isEmpty())
            throw underflow_error("Queue is empty");

        if (front == rear){
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX_SIZE;
    }

    int getFront() const{
        if (isEmpty())
            throw underflow_error("Queue is empty");
        return data[front];
    }

    bool isEmpty() const{
        return front == -1 && rear == -1;
    }

    bool isFull() const{
        return (rear + 1) % MAX_SIZE == front;
    }
};

#endif

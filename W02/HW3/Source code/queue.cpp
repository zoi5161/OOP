#include "queue.h"

Queue::Queue(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    frontIndex = 0;
    rearIndex = -1;
    size = 0;
}

Queue::~Queue(){
    delete[] arr;
}

bool Queue::isEmpty() const{
    return size == 0;
}

bool Queue::isFull() const{
    return size == capacity;
}

void Queue::enqueue(int item){
    if (isFull())
        return;
    rearIndex = (rearIndex + 1) % capacity;
    arr[rearIndex] = item;
    size++;
}

int Queue::dequeue(){
    if (isEmpty())
        return -1;
    int frontValue = arr[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    size--;
    return frontValue;
}

int Queue::getFrontValue() const{
    if (isEmpty())
        return -1;
    return arr[frontIndex];
}

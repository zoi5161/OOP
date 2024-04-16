#include "queue.h"

int main(){
    Queue queue(5);
    int value;

    if(queue.isEmpty())
        cout << "Queue is empty" << endl;
    if(queue.isFull())
        cout << "Queue is full" << endl;

    for (int i = 1; i <= 5; i++)
        queue.enqueue(i);
    cout << "Queue: [1, 2, 3, 4, 5]" << endl;

    if(queue.isEmpty())
        cout << "Queue is empty" << endl;
    if(queue.isFull())
        cout << "Queue is full" << endl;

    cout << "Front value: " << queue.getFrontValue() << endl << endl;

    while (!queue.isEmpty()){
        value = queue.dequeue();
        cout << "Dequeued: " << value << endl;
    }

    return 0;
}

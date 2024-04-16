#include "stack.h"

int main(){
    Stack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack: [1, 2, 3]" << endl;
    cout << "Top value: " << myStack.getTopValue() << endl << endl;

    while (!myStack.isEmpty())
        cout << "Popped: " << myStack.pop() << endl;

    return 0;
}
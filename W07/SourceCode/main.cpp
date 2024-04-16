#include "Fraction.h"
#include "Array.h"
#include "IntFormat.h"
#include "DateFormat.h"
#include "TimeFormat.h"
#include "File.h"
#include "Stack.h"
#include "Queue.h"

int main(){
    // Bai 1
    int numerator;
    int denominator;
    int ans;
    Fraction f;

    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;

    try{
        f.SetValue(numerator, denominator);
        f.print();
    }
    catch (DividedByZeroException& ex){
        cout << ex.what() << endl;
    }

    // Bai 2
    int size;
    int index;

    cout << "Enter the number of elements of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    try{
        Array array(arr, size);
        delete []arr;
        cout << "Enter the index of the element to search: ";
        cin >> index;
        cout << "Value: " << array.getValueAt(index) << endl << endl;
    }
    catch(IndexOutOfRangeException& ex){
        cout << endl << ex.what() << endl;
    }

    // Bai 3
    string fileName;
    cout << "Enter file name: ";

    cin >> fileName;
    ifstream isFileExist(fileName);

    try{
        if(!isFileExist.good())
            throw FileNotFoundException();
        else
            cout << "Valid file path" << endl << endl;
    }
    catch(FileNotFoundException& ex){
        cout << endl << ex.what() << endl;
    }

    // Bai 4
    string s;
    bool invalid = false;

    cout << "Enter a string of an integer: ";
    cin >> s;

    for(int i = 0; i < s.length(); i++)
        if(s[i] < '0' || s[i] > '9'){
            invalid = true;
            break;
        }

    try{
        if(invalid)
            throw IntegerFormatException();
        cout << "After change string to integer: " << stoi(s) << endl << endl;
    }
    catch(IntegerFormatException& ex){
        cout << endl << ex.what() << endl;
    }

    // Bai 5
    string date;
    int cnt = 0, day, month, year;
    cout << "Enter date (DD/MM/YYYY): ";
    cin >> date;

    invalid = false;
    s = "";

    if(date.length() != 10)
        invalid = true;
    else{
        for(int i = 0; i < date.length(); i++){
            if((date[i] < '0' || date[i] > '9') && i != 2 && i != 5){
                invalid = true;
                break;
            }
            
            if((i == 2 || i == 5) && date[i] != '/'){
                invalid = true;
                break;
            }

            if(date[i] == '/'){
                if(cnt == 0)
                    day = stoi(s);
                else 
                    month = stoi(s);
                cnt++;
                s = "";
            }
            else 
                s += date[i];
        }

        year = stoi(s);
        
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day > 31)
                invalid = true;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day > 30)
                invalid = true;
        }
        else if(month == 2){
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                if(day > 29)
                    invalid = true;
            }
            else
                if(day > 28)
                    invalid = true;
        }
        else 
            invalid = true;
    }

    try{
        if(invalid)
            throw DateFormatException();
        cout << "Date: " << date << endl << endl;
    }
    catch(DateFormatException& ex){
        cout << endl << ex.what() << endl;
    }

    // Bai 6
    string time;
    int hour, minute, second;
    cout << "Enter time (HH:MM:SS): ";
    cin >> time;

    cnt = 0;
    s = "";
    invalid = false;

    if(time.length() != 8)
        invalid = true;
    else{
        for(int i = 0; i < time.length(); i++){
            if((time[i] < '0' || time[i] > '9') && i != 2 && i != 5){
                invalid = true;
                break;
            }
            
            if((i == 2 || i == 5) && time[i] != ':'){
                invalid = true;
                break;
            }

            if(time[i] == ':'){
                if(cnt == 0)
                    hour = stoi(s);
                else 
                    minute = stoi(s);
                cnt++;
                s = "";
            }
            else 
                s += time[i];
        }

        second = stoi(s);
        
        if(hour > 23 || minute > 59 || second > 59)
            invalid = true;
    }

    try{
        if(invalid)
            throw TimeFormatException();
        cout << "Time: " << time << endl << endl;
    }
    catch(TimeFormatException& ex){
        cout << endl << ex.what() << endl;
    }

    // Bai 7
    Stack myStack;
    Queue myQueue;
    try{
        
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);

        cout << "After push 10 20 30 into stack" << endl;
        cout << "Top of Stack: " << myStack.getTop() << endl << endl;

        myStack.pop();
        cout << "After pop stack one time" << endl;
        cout << "Top of Stack after pop: " << myStack.getTop() << endl << endl;

        myQueue.enqueue(40);
        myQueue.enqueue(50);
        myQueue.enqueue(60);

        cout << "After push 40 50 60 into stack" << endl;
        cout << "Front of Queue: " << myQueue.getFront() << endl << endl;

        myQueue.dequeue();
        cout << "After pop queue one time" << endl;
        cout << "Front of Queue after dequeue: " << myQueue.getFront() << endl;

    } 
    catch (const exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
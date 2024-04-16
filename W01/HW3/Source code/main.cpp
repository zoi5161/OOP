#include "Point.cpp"

int main(){
    system("clear");
    Point A, B;
    double x, y;
    string choice = "1", skip = "0";

    cout << "Enter the x coordinate: ";
    cin >> x;

    cout << "Enter the y coordinate: ";
    cin >> y;

    A.Input(x, y);
    cout << endl;

    while(1)
    {
        if(choice >= "1" && choice <= "4")
        {
            A.Output();
            cout << endl << "- - - - Options - - - -" << endl;
            cout << "1. Enter a new point" << endl;
            cout << "2. Print a point" << endl;
            cout << "3. Calculate the distance to a new point" << endl;
            cout << "4. Exit" << endl;
            cout << endl << "Your choice: ";
        }

        cin >> choice;
        if(choice == "1")
        {
            cout << endl << "Enter the x coordinate: ";
            cin >> x;

            cout << "Enter the y coordinate: ";
            cin >> y;

            A.Input(x, y);
            cout << endl;
            A.Output();
        }
        else if(choice == "2")
        {
            cout << endl;
            A.Output();
        }
        else if(choice == "3")
        {
            cout << endl << "Enter the x coordinate: ";
            cin >> x;

            cout << "Enter the y coordinate: ";
            cin >> y;

            B.Input(x, y);
            cout << endl;
            B.Output();

            cout << endl << "Distance: " << A.Distance(B) << endl;
        }
        else if(choice == "4")
            break;
        else
        {
            cout << "Invalid choice. Please enter again (1 -> 4): ";
            continue;
        }

        cout << "Do you want to continue (Y/N): ";
        
        while(1)
        {
            cin >> skip;
            if(skip == "Y" || skip == "y")
            {
                system("clear");
                break;
            }
            else if(skip == "N" || skip == "n")
            {
                system("clear");
                return 0;
            }
            else 
                cout << "Invalid choice. Please enter again (Y/N): ";
        }
    }
    return 0;
}
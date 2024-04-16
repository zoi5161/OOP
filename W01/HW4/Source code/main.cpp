#include "Point2D.cpp"
#include "Rectangle.cpp"

int main(){
    system("clear");
    Rectangle rectangle;

    cout << "Enter the information of the rectangle" << endl;
    rectangle.input();

    if(rectangle.isValid()) 
    {
        cout << "Valid rectangle" << endl;
        cout << "Perimeter: " << rectangle.perimeter() << endl;
        cout << "Area: " << rectangle.area() << endl;
    } 
    else
        cout << "Invalid rectangle" << endl;

    return 0;
}

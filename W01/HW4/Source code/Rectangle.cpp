#include "Rectangle.h"
#include "Point2D.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(){
    vertices = new Point2D[4];
}

Rectangle::~Rectangle(){
    delete[] vertices;
}

void Rectangle::input(){
    double x, y;
    cout << "Enter the vertices clockwise" << endl << endl;
    for (int i = 0; i < 4; i++){
        cout << "Vertex " << i + 1 << ": " << endl;
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        vertices[i].setX(x);
        vertices[i].setY(y);
        cout << endl;
    }
}

bool Rectangle::isValid(){
    double lengths[4];
    for (int i = 0; i < 4; i++){
        int next_index = (i + 1) % 4;
        double x1 = vertices[i].getX();
        double y1 = vertices[i].getY();
        double x2 = vertices[next_index].getX();
        double y2 = vertices[next_index].getY();
        lengths[i] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        if(lengths[i] == 0)
            return false;
    }

    return lengths[0] == lengths[2] && lengths[1] == lengths[3];
}

double Rectangle::perimeter(){
    double lengths[4];
    for (int i = 0; i < 4; i++){
        int next_index = (i + 1) % 4;
        double x1 = vertices[i].getX();
        double y1 = vertices[i].getY();
        double x2 = vertices[next_index].getX();
        double y2 = vertices[next_index].getY();
        lengths[i] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    double p = 0;
    for (int i = 0; i < 4; i++)
        p += lengths[i];

    return p;
}

double Rectangle::area(){
    double lengths[4];
    for (int i = 0; i < 4; i++){
        int next_index = (i + 1) % 4;
        double x1 = vertices[i].getX();
        double y1 = vertices[i].getY();
        double x2 = vertices[next_index].getX();
        double y2 = vertices[next_index].getY();
        lengths[i] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

    double a = lengths[0];
    double b = lengths[1];
    return a * b;
}

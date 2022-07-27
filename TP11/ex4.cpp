#include <iostream>
#include <vector>
#include "Figure.h"

using namespace std;

class Rectangle : public Figure {
    public:
    Rectangle(double x_center, double y_center, double width, double heigth) : Figure(x_center, y_center) {
        width_ = width;
        heigth_ = heigth;
    }
    void draw() const {
        cout << "R" << "(" << x_center_ << "," << y_center_ << ")" << "(" << width_ << "," << heigth_ << ")";
        
    }
    ~Rectangle () {};

    private:
        double width_;
        double heigth_;

};

class Circle : public Figure {
    public:
    Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center) {
        radius_ = radius;
    }
    void draw() const {
        cout << "C" << "(" << x_center_ << "," << y_center_ << ")" << "(" << radius_ << ")";
    }
    ~Circle () {};
    private:
        double radius_;

};
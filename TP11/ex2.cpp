#include <iostream>
#include <cmath>
#include "Shape.h"

/*
This exercise works with classes' inheritance, so we'll have to call two class constructors:
    - Subclass' constructor;
    - Main class' constructor;

We'll have to use accessor in the subclass because we can't get to the private attributes of 
the main class.
*/


class Circle : public Shape {
    public:
    Circle(point center, double radius) : Shape(center) {
        radius_ = radius;
    }
    double perimeter() const {
        return (2 * M_PI * radius_);
    };

    double area() const {
        return (M_PI * radius_ * radius_);
    };

    bool contains(const point& p) const {
        return (pow((p.x - get_center().x),2) + pow((p.y - get_center().y),2) <= pow(radius_,2)); // Using Descartes's Circle Equation
    };

    private:
        double radius_;
};


class Rectangle : public Shape {
    public:
    Rectangle(point center, double width, double heigth) : Shape(center) {
        width_ = width;
        heigth_ = heigth;
    }
    double perimeter() const {
        return (width_ * 2 + heigth_ * 2);
    };

    double area() const {
        return (width_ * heigth_);
    };

    bool contains(const point& p) const {
        return (p.x <= get_center().x + width_/2) && (p.x >= get_center().x - width_/2) && (p.y <= get_center().y + heigth_/2) && (p.y >= get_center().y - heigth_/2);
    };
    private:
        double width_;
        double heigth_;
};
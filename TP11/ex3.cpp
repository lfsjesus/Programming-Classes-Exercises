#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() : x_(0), y_(0){}

Point::Point(int x, int y) : x_(x), y_(y){}

Point::Point(const Point& p) : x_(p.x_), y_(p.y_){}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

Point& Point::operator=(const Point& p){
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point Point::operator+(const Point& p) const{

    Point result {0,0};

    result.x_ = x_ + p.x_;
    result.y_ = y_ + p.y_;
    return result;
}

Point& Point::operator+=(const Point& p){
    x_ += p.x_;
    y_ += p.y_;
    return *this;

}

Point Point::operator*(int v) const{
    Point result {0,0};
    result.x_ = x_*v; 
    result.y_ = y_*v;
    return result;

}

Point operator*(int x, const Point& p){
    Point result {0,0};
    result = p * x;
    return result;

}

std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;

}
#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(int x, int y) {
    x_ = x;
    y_ = y;
}

float Point::distance(const Point& point) const {
    return sqrt((x_ - point.x_)*(x_ - point.x_) + (y_ - point.y_)*(y_ - point.y_));
}

void Point::show() const {
    cout << "(" << x_ << "," << y_ << ")";
}
#include <iostream>
#include <vector>
#include "Polygon.h"
#include "Point.h"

using namespace std;

Polygon::Polygon() {
    v_ = {};
}

Polygon::Polygon(std::vector<Point> v) {
    v_ = v;
}

void Polygon::show() const {
    cout << "{";
    for (Point p : v_) {
        p.show();
    }
    cout << "}";
}

bool Polygon::get_vertex(size_t position, Point& p){
    if (position > v_.size() || position <= 0) {
        return false;
    }
    p = v_[position - 1]; 
    return true;
    
}

void Polygon::add_vertex(int position, Point p){
    v_.insert(v_.begin() + position - 1, p);
}

float Polygon::perimeter() const{
    float total = v_[0].distance(v_.back());
    for (size_t i = 0; i < v_.size() - 1; i++) {
        total = total + v_[i].distance(v_[i+1]);
    }

    return total;
}







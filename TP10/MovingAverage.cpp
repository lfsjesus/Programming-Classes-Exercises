#include <iostream>
#include "MovingAverage.h"
#include <list>

MovingAverage::MovingAverage(std::size_t n) {
    n_ = n;
    values_ = {};
} 

void MovingAverage::update(double value) {
    if (values_.size() == n_) {
        values_.pop_front();
    }
    values_.push_back(value);
}

double MovingAverage::get() const {
    double average = 0;
    for (double el:values_) {
        average = average + el/values_.size();
    }
    return average;
}
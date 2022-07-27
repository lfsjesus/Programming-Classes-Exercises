#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

Date::Date() {
    year_ = 1;
    month_ = 1;
    day_ = 1;
}

Date::Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

bool Date:: is_before(const Date& date) const {
    if (date.year_ > year_) {
        return true;
    }
    else {
        if (date.year_ == year_) {
            if (date.month_ > month_) {
                return true;
            }
            else {
                if (date.month_== month_) {
                    if (date.day_ < day_) {
                        return false;
                    }
                    return true;;
                }
            }
            return false;
        }
        return false;;
    }
}


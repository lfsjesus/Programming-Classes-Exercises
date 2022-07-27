#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date2.h"

using namespace std;

Date::Date() {
    year = 1;
    month = 1;
    day = 1;
}

int days_in_month(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

Date::Date(int year, int month, int day) {
    if(year>=1 && year<=9999)   this->year = year;
    else {this->year = 0;}
    if(month>=1 && month <= 12) this->month = month;
    else {this->month = 0;}
    if(day>=1 && day<=days_in_month(year,month)) this->day = day;
    else {this->day = 0;}
}

Date::Date(const std::string& year_month_day) {
    istringstream iss(year_month_day);
    int year, month, day;
    char sep1, sep2;
    iss >> year >> sep1 >> month >> sep2 >> day;
    if(year>=1 && year<=9999)   this->year = year;
    else {this->year = 0;}
    if(month>=1 && month <= 12) this->month = month;
    else {this->month = 0;}
    if(day>=1 && day<=days_in_month(year,month)) this->day = day;
    else {this->day = 0;}
    if (sep1 != '/' || sep2 != '/') {this->year = 0; this->month = 0;this->day = 0;}
}

bool Date::is_valid() const {
    return not (day == 0 || month == 0 || year == 0);
}
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date3.h"

using namespace std;
int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}


Date::Date() {
    yyyymmdd = "00010101";
}

Date::Date(int year, int month, int day) {
    if(!(year>=1 && year<=9999))   {yyyymmdd = "00000000"; return;}
    if (!(month>=1 && month <= 12)) {yyyymmdd = "00000000"; return;}
    if(!(day>=1 && day<=num_days(year,month))) {yyyymmdd = "00000000"; return;}

    ostringstream oss;
    oss.fill('0');
    oss.width('4');
    oss << year;
    oss.width('2');
    oss << month;
    oss.width('2');
    oss << day;

    yyyymmdd = oss.str();
}


Date::Date(const std::string& year_month_day) {
    istringstream iss(year_month_day);
    int year, month, day;
    char sep1, sep2;
    iss >> year >> sep1 >> month >> sep2 >> day;
    if (!(year>=1 && year<=9999 && sep1 == '/' && sep2 == '/')) {yyyymmdd = "00000000"; return;}
    if (!(month>=1 && month <= 12 && sep1 == '/' && sep2 == '/')) {yyyymmdd = "00000000"; return;}
    if (!(day>=1 && day<=num_days(year,month) && sep1 == '/' && sep2 == '/')) {yyyymmdd = "00000000"; return;}

    ostringstream oss;
    oss.fill('0');
    oss.width(4);
    oss << year;
    oss.width(2);
    oss << month;
    oss.width(2);
    oss << day;
    yyyymmdd = oss.str();
}

int Date::get_year() const {
    return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const {
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const {
    return stoi(yyyymmdd.substr(6, 2));
}

bool Date::is_valid() const {
    return (yyyymmdd != "00000000");
}
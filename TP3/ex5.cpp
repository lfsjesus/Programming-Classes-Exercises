#include <iostream>
using namespace std;


struct time_of_day {
  unsigned char h;  // hours (0 to 23)
  unsigned char m;  // minutes (0 to 59)
};

struct interval {
  time_of_day start;  // start time
  time_of_day end;    // end time
};

//! Prints the results.
void print(int d, const interval il) {
  cout << d << " ["
       << (int) il.start.h << ':' << (int) il.start.m << ','
       << (int) il.end.h   << ':' << (int) il.end.m 
       << "[\n";
}

bool before(time_of_day n, time_of_day t) {
    if (n.h == t.h) {
        if (n.m < t.m) {
            return true;
        }   
    return false; 
    }
    else {
        return (n.h < t.h);
    }
}

bool is_in(interval n, time_of_day t) {
    return (!before(t, n.start) && before(t, n.end));
}


int search_intervals(time_of_day t, const interval a[], int n, interval& u) {
    u.start = t;
    u.end = t;
    bool belongs = false;
    for (int i = 0; i < n; i++) {
        if (is_in(a[i], t)) {
            belongs = true;
            if (before(a[i].start, u.start )) {
                u.start = a[i].start;
            }
            if (!before(a[i].end, u.end)) {
                u.end = a[i].end;
            }

        }
    }
    if (!belongs) {
        return 0;
    }
    else {
        return 60 * (u.end.h - u.start.h) + u.end.m - u.start.m;
    }

}


int main() {
    const int n = 2;
    const time_of_day t = { 14, 30 };
    interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    print(d, u);
}

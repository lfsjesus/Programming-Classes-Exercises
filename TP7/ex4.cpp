#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

double average(const string& fname) {
    ifstream in(fname);
    double num = 0;
    double els = 0;
    double acc = 0;

    while (!in.eof()) {
        if (in >> num) {
            acc += num;
            els += 1;
        }
        else {
            in.clear();
            in.ignore(1);
        }
    }

    return acc/els;
}

int main() {
    double m = average("p4_test1.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
}

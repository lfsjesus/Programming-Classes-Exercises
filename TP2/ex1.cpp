#include <iostream>
using namespace std;

int adigits(int a, int b, int c) {
    if (a >= b && a>= c) {
        if (b >= c) {
            return (a*10 + b) * 10 + c;
        }

        if (b < c) {
            return (a*10 +c) * 10 + b;
        }
    }

    else if (b >= a && b>= c) {
        if (a >= c) {
            return (b*10 + a) * 10 + c;
        }

        if (a < c) {
            return (b*10 +c) * 10 + a;
        }
    }

    else if (c >= b && c>= a) {
        if (b >= a) {
            return (c*10 + b) * 10 + a;
        }

        if (b < c) {
            return (c*10 +a) * 10 + b;
        }
    }
    return 0;
}

int main() {
    
}
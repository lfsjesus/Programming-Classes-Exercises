#include <iostream>

using namespace std;

bool is_leap(int a) {
    if (a % 4 == 0){
        if (a%100== 0 && a%400 != 0) {
            return false;
        }
        return true;
    }
    return false;
}

void advance(int delta, int& d, int& m, int& y) {

    for (int x = 0; x < delta; x++) {

        switch(m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            d += 1;
            if (d > 31) {
                d = 1;
                m += 1;
            }

            if (m > 12) {
                m = 1;
                y += 1;
            }
            break;

            case 4: case 6: case 9: case 11:
            d += 1;
            if (d > 30) {
                d = 1;
                m += 1;
            }
            break;

            case 2:
            d += 1;
            if (is_leap(y)) {
                if (d > 29) {
                    d = 1;
                    m += 1;
                }
            }
            else {
                if (d > 28) {
                    d = 1;
                    m += 1;
                }
            }

            break;

        }

    }

}

int main() {

    int d = 1, m = 1, y = 2022; advance(0, d, m, y); cout << d << ' ' << m << ' ' << y;
    
}
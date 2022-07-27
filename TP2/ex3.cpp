#include <iostream>
using namespace std;

bool is_mersenne_number(unsigned long n) {
    if (n > 0) {
        while (n > 0) {
            if (n % 2 == 0) {
                return false;
            }
            n = n / 2;
        }
        return true;
    }
    return false;
}

int main() {
    
}
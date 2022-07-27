#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n > 1) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
        }
    } 
    return true;
    }
    return false;
}
int count_ones(int n) {
    int ones = 0;
    while (n != 0) {
        if (n % 2 == 1 ){
            ones++;
        }
        n = n / 2;
    }
    return ones;
}

bool is_pernicious (int n) {
    return (is_prime(count_ones(n)) && is_prime(n));
}

int main () {
    int a;
    int b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (is_pernicious(i)) {
            cout << i << "\n";
        }
    }
}
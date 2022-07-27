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

int main () 
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
           cout << i;
           cout << "\n";
        }
    }
    
}
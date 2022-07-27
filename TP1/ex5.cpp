#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () 
{
    int k;
    int d;
    cin >> k >> d;

    double value;
    for (int n = 0; n <= k; n++) {
        value = value + 4.0 * (pow(-1, n) / (double)(2*n + 1));
    }
    cout << fixed << setprecision(d) << value;

}
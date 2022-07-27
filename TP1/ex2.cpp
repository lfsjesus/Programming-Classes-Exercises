#include <iostream>

using namespace std;

int main() 
{
    int number;
    int reverse_number = 0;
    cin >> number;

    while (number != 0) {
        reverse_number = reverse_number * 10 + number % 10;
        number = number / 10;
    }
    cout << reverse_number;
}
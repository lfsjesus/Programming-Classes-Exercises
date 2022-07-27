#include <iostream>
using namespace std;


int main() {
    char i;
    cin >> i;


    if ((i >= 'A' && i<= 'Z') || (i >= 'a' && i <= 'z')) {
        cout << "LETTER";
    }

    else if (i >= '0' && i<='9') {
        cout << "DIGIT";
    }

    else {
        cout << "OTHER";
    }
}
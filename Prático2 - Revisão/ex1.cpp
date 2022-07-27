#include <iostream>
#include <string>
using namespace std;

bool pangram(const string& s, string& m) {
    int alpha[26] = {0};

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            alpha[c - 'A'] = 1;
        }
        else if (c >= 'a' && c <= 'z') {
            alpha[c - 'a'] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            m.push_back(i + 'a');
        } 
    }

    if (m == "") return true;
    return false;
}

int main() {


return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count(const string& fname, const string& word) {
    ifstream in(fname);
    string r;
    string find = word;
    int count = 0;

    for (char& c: find) {
        c = toupper(c);
    }

    while(in >> r) {
        
        for (char& c: r) {
            c = toupper(c);
        }

        if (r == find) count += 1;
    }

    return count;
}

int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
}
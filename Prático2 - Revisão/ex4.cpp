#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longest_prefix(const vector<string>& v) {
    string prefix;
    int char_num = 0;
    for (char c : v[0]) {
        for (string s : v) {
            if (s[char_num] != c) return prefix;
        }
        prefix.push_back(c);
        char_num++;
    }
    return prefix;
}